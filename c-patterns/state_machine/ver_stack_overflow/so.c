#include <stdio.h>
#include <assert.h>





typedef enum ret_codes 
{ ok,
  fail,
  repeat
} ret_code_t;

typedef enum state_codes 
{
    entry,
    foo,
    bar,
    end
} state_code_t;

typedef struct transition {
    enum state_codes src_state;
    enum ret_codes   ret_code;
    enum state_codes dst_state;
}transition_t;


transition_t state_transitions[] = {
    {entry, ok,     foo},
    {entry, fail,   end},
    {foo,   ok,     bar},
    {foo,   fail,   end},
    {foo,   repeat, foo},
    {bar,   ok,     end},
    {bar,   fail,   end},
    {bar,   repeat, foo}};


#define EXIT_STATE end
#define ENTRY_STATE entry
#define TRANSITION_COUNT 8

/* array and enum below must be in sync! */
ret_code_t entry_state(void);
ret_code_t foo_state(void);
ret_code_t bar_state(void);
ret_code_t exit_state(void);

ret_code_t (* state[])(void) = { entry_state, foo_state, bar_state, exit_state};



state_code_t lookup_transitions(enum state_codes current_state, enum ret_codes ret_val)
{
    int i;

    for (i = 0; i < TRANSITION_COUNT; i++)
    {
        if ((state_transitions[i].src_state == current_state) && (state_transitions[i].ret_code == ret_val))
            return state_transitions[i].dst_state;
    }

    assert(0);
}

int main(int argc, char *argv[]) {
    state_code_t cur_state = ENTRY_STATE;
    ret_code_t rc;
    ret_code_t (* state_fun)(void);

    for (;;) {
        state_fun = state[cur_state];
        rc = state_fun();
        if (EXIT_STATE == cur_state)
            break;
        cur_state = lookup_transitions(cur_state, rc);
    }

    return 0;
}

ret_code_t entry_state(void)
{   
    printf("in entry_state returning ok\n");
    return ok;
}

ret_code_t foo_state(void)
{
   static int i = 0;
   if (i++ < 5)
   {
       printf("in foo_state i = %d , returning repeat\n", i);
       return repeat;
   }
   else 
   {
       printf("in foo_state i = %d , returning ok\n", i);
       return ok;
   }
}

ret_code_t bar_state(void)
{
    static int i = 0;
    if (i++ < 5)
    {
       printf("in bar_state i = %d , returning repeat\n", i);
       return repeat;
    }
    else
    {
       printf("in bar_state i = %d , returning ok\n", i);
       return ok;
    }
}

ret_code_t exit_state(void)
{
    printf("in exit state\n");
    return ok;
}
