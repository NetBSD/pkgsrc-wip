# $NetBSD$
PKG_OPTIONS_VAR=	PKG_OPTIONS.OpenSTA
PKG_SUPPORTED_OPTIONS=	notclreport debug

.include "../../mk/bsd.options.mk"

# If you are using OpenSTA as a library without tcl, to avoid running into issues with tcl, set this option
.if !empty(PKG_OPTIONS:Mnotclreport)
CXXFLAGS+=	-DNOTCLREPORT
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif
