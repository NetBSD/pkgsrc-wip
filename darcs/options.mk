# $NetBSD: options.mk,v 1.5 2014/07/24 21:20:38 szptvlfn Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.darcs
PKG_SUPPORTED_OPTIONS=	terminfo color mmap

PKG_OPTIONS_REQUIRED_GROUPS+=	http-lib
PKG_OPTIONS_GROUP.http-lib=	curl http

PKG_SUGGESTED_OPTIONS=	http terminfo color mmap

.include "../../mk/bsd.options.mk"

#
# Curl or HTTP
#
.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+= -fcurl -f-http
.include "../../www/curl/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mhttp)
CONFIGURE_ARGS+= -f-curl -fhttp
.include "../../www/hs-HTTP/buildlink3.mk"
.endif

#
# terminfo
#
.if !empty(PKG_OPTIONS:Mterminfo)
CONFIGURE_ARGS+= -fterminfo
.include "../../wip/hs-terminfo/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-terminfo
.endif

#
# color
#
.if !empty(PKG_OPTIONS:Mcolor)
CONFIGURE_ARGS+=	-fcolor
.else
CONFIGURE_ARGS+=	-f-color
.endif

#
# mmap
#
.if !empty(PKG_OPTIONS:Mmmap)
CONFIGURE_ARGS+= -fmmap
.include "../../wip/hs-mmap/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-mmap
.endif
