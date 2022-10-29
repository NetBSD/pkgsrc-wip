# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.yosys

PKG_OPTIONS_REQUIRED_GROUPS=	compiler
PKG_OPTIONS_GROUP.compiler=	gcc clang

PKG_SUGGESTED_OPTIONS=	clang

# On NetBSD only clang allows Yosys to pass its self tests.
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS=	clang
.else
PKG_SUGGESTED_OPTIONS=	gcc
.endif

.include "../../mk/bsd.options.mk"

###
### Use clang to build Yosys
###
.if !empty(PKG_OPTIONS:Mclang)
YOSYS_CONFIG=		clang
BUILD_DEPENDS+=		clang-[0-9]*:../../lang/clang
PKGSRC_COMPILER=	clang
.endif

###
### Use GCC to build Yosys
###
.if !empty(PKG_OPTIONS:Mgcc)
YOSYS_CONFIG=		gcc
GCC_REQD+=		4.8.1
.endif
