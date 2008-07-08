# $NetBSD: options.mk,v 1.1.1.1 2008/07/08 15:51:15 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zsh
PKG_SUPPORTED_OPTIONS=	static zsh-multibyte pcre wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--disable-dynamic
.else
DLOPEN_REQUIRE_PTHREADS=no
.  include "../../mk/dlopen.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzsh-multibyte)
CONFIGURE_ARGS+=	--enable-multibyte
.endif

.if !empty(PKG_OPTIONS:Mpcre)
PCRE_CONFIG=		${BUILDLINK_PREFIX.pcre}/bin/pcre-config
CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ENV+=		PCRE_CONFIG=${PCRE_CONFIG:Q}
.  include "../../devel/pcre/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
WITH_TERM_LIBS+=	ncursesw
.  include "../../devel/ncursesw/buildlink3.mk"
.endif
