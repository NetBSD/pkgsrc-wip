# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.kore
PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

# Build with asynchronous curl support.
.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
MAKE_FLAGS+=	CURL=1
USE_TOOLS+=	pkg-config
.endif
