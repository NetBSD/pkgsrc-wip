PKG_OPTIONS_VAR= PKG_OPTIONS.openblas
# Choose dynamic target/processor choice at runtime or
# fixed build with build host CPU.
PKG_OPTIONS_GROUP.target= dynamic fixed
# Threading model. Pthread seems more robust e.g. with numpy usage.
PKG_OPTIONS_GROUP.threading = single pthread openmp
PKG_OPTIONS_REQUIRED_GROUPS= target threading
PKG_SUGGESTED_OPTIONS= dynamic pthread

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdynamic)
MAKE_ENV+=      DYNAMIC_ARCH=1
.else
MAKE_ENV+=      DYNAMIC_ARCH=0
.endif

.if   !empty(PKG_OPTIONS:Mopenmp)
MAKE_ENV+=      USE_OPENMP=1 NO_AFFINITY=1
.elif !empty(PKG_OPTIONS:Mpthread)
MAKE_ENV+=      USE_OPENMP=0 USE_THREAD=1
.else
MAKE_ENV+=      USE_OPENMP=0 USE_THREAD=0
.endif
