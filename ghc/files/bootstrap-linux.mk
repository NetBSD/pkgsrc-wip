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
ghc_stage2_v_EXTRA_CC_OPTS += -L[[PREFIX]]/lib -lm -liconv -lrt -ldl
utils/ghc-pkg_dist-install_v_EXTRA_CC_OPTS += -L[[PREFIX]]/lib -lm -liconv -lrt -ldl -lncurses

SRC_CC_OPTS += -I[[PREFIX]]/include
INTEGER_LIBRARY = integer-simple

# Unregisterised stage0 compiler runs way too slow without GCC's
# optimisation. The stage1 (which is also unregisterised) is still
# slow, but then we have to append CONF_CC_OPTS_STAGE0="-O2" to
# CONFIGURE_ARGS as well.
EXTRA_CC_OPTS += -O2
