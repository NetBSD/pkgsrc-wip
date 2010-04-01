GHC = false
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
ghc_stage2_v_EXTRA_CC_OPTS += -L[[PREFIX]]/lib -lm -liconv
utils/ghc-pkg_dist-install_v_EXTRA_CC_OPTS += -L[[PREFIX]]/lib -lm -liconv -lncurses

SRC_CC_OPTS += -I[[PREFIX]]/include
INTEGER_LIBRARY = integer-simple
