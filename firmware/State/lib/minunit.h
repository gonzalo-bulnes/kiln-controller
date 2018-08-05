/*
 * Minunit is a minimal unit testing framework for C.
 * See http://www.jera.com/techinfo/jtns/jtn002.html for details.
 */

/* file: minunit.h */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { const char *message = test(); tests_run++; \
                               if (message) return message; } while (0)
extern int tests_run;
