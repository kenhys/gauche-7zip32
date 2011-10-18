/*
 * gauche_7zip32.c
 */

#include "gauche_7zip32.h"

/*
 * The following function is a dummy one; replace it for
 * your C function definitions.
 */
ScmClass *C7Zip32Class;
ScmClass *CHarcClass;

ScmObj test_gauche_7zip32(void)
{
    return SCM_MAKE_STR("gauche_7zip32 is working");
}

/*
 * Module initialization function.
 */
extern void Scm_Init_gauche_7zip32lib(ScmModule*);

static void c7zip32_print(ScmObj obj, ScmPort *out, ScmWriteContext *ctx)
{
  Scm_Printf(out, "#<7zip32>");
}

static void c7zip32_cleanup(ScmObj obj)
{
    C7Zip32 *q;
    q = C7ZIP32_UNBOX(obj);
}
static void charc_print(ScmObj obj, ScmPort *out, ScmWriteContext *ctx)
{
  Scm_Printf(out, "#<harc>");
}

static void charc_cleanup(ScmObj obj)
{
    CHarc *q;
    q = CHARC_UNBOX(obj);
}

void Scm_Init_gauche_7zip32(void)
{
  ScmModule *mod;

  /* Register this DSO to Gauche */
  SCM_INIT_EXTENSION(gauche_7zip32);

  /* Create the module if it doesn't exist yet. */
  mod = SCM_MODULE(SCM_FIND_MODULE("os.windows.7zip32", TRUE));

  C7Zip32Class =
    Scm_MakeForeignPointerClass(mod, "<7zip32>",
                                c7zip32_print,
                                c7zip32_cleanup,
                                SCM_FOREIGN_POINTER_KEEP_IDENTITY|SCM_FOREIGN_POINTER_MAP_NULL);
  CHarcClass =
    Scm_MakeForeignPointerClass(mod, "<harc>",
                                charc_print,
                                charc_cleanup,
                                SCM_FOREIGN_POINTER_KEEP_IDENTITY|SCM_FOREIGN_POINTER_MAP_NULL);

  /* Register stub-generated procedures */
  Scm_Init_gauche_7zip32lib(mod);
}
