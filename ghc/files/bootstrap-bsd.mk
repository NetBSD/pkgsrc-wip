OMIT_PHASE_0 = YES
OMIT_PHASE_1 = YES
GHC = false
GHC_STAGE1 =
GHC_PKG_INPLACE =
GHC_CABAL_INPLACE =
DUMMY_GHC_INPLACE =
UNLIT =
NO_INCLUDE_DEPS = YES
GhcUnregisterised = YES
GhcLibWays = v
GhcRTSWays =
SplitObjs = NO
GhcWithNativeCodeGen = NO
GhcWithInterpreter = NO
GhcWithSMP = NO
ghc_stage2_v_EXTRA_CC_OPTS += -L[[PREFIX]]/lib -lm -liconv -lutil -lrt
utils/ghc-pkg_dist-install_v_EXTRA_CC_OPTS += -L[[PREFIX]]/lib -lm -liconv -lutil -lrt -lncurses

SRC_CC_OPTS += -I[[PREFIX]]/include
INTEGER_LIBRARY = integer-simple

#   Unregisterised stage0 compiler gets too large (.text section being
# over 64 MiB) without -Os, exceeding NetBSD/i386's kernel default
# limitation.
#   Note that stage1 currently doesn't bloat that much (about 42.6
# MiB), but when it does we have to append CONF_CC_OPTS_STAGE1="-Os"
# to CONFIGURE_ENV as well. I guess that's a matter of time :(
EXTRA_CC_OPTS += -Os
