/*
 * gauche_7zip32.c
 */

#include "gauche_7zip32.h"

/*
 * The following function is a dummy one; replace it for
 * your C function definitions.
 */

ScmObj test_gauche_7zip32(void)
{
    return SCM_MAKE_STR("gauche_7zip32 is working");
}

/*
 * Module initialization function.
 */
extern void Scm_Init_gauche_7zip32lib(ScmModule*);

void Scm_Init_gauche_7zip32(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(gauche_7zip32);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE("gauche_7zip32", TRUE));

    /* Register stub-generated procedures */
    Scm_Init_gauche_7zip32lib(mod);
}
