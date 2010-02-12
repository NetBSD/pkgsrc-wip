# $NetBSD: options.mk,v 1.2 2010/02/12 06:50:59 phonohawk Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.darcs
PKG_SUPPORTED_OPTIONS=	zlib terminfo color mmap

PKG_OPTIONS_OPTIONAL_GROUPS+=	http-lib
PKG_OPTIONS_GROUP.http-lib=		curl http

PKG_SUGGESTED_OPTIONS=	http zlib terminfo color mmap

.include "../../mk/bsd.options.mk"

#
# Curl or HTTP
#
.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+= -fcurl -fcurl-pipelining -f-http
.include "../../www/curl/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mhttp)
CONFIGURE_ARGS+= -f-curl -fhttp
.include "../../wip/hs-HTTP/buildlink3.mk"
.endif

#
# Zlib
#
.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+= -fzlib
.include "../../wip/hs-zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-zlib
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
CONFIGURE_ARGS+= -fcolor
.else
CONFIGURE_ARGS+= -f-color
.endif

#
# mmap
#
.if !empty(PKG_OPTIONS:Mmmap)
CONFIGURE_ARGS+= -fmmap
.include "../../wip/hs-mmap4/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-mmap
.endif
