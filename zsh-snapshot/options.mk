# $NetBSD: options.mk,v 1.1.1.1 2008/09/09 02:32:19 bsadewitz Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.zsh
PKG_SUPPORTED_OPTIONS=		wide-curses pcre static
PKG_OPTIONS_GROUP.zsh=		zsh-maildir zsh-multibyte 
###
### AIX breaks with zsh-mem, according to documentation.
###
.if ${OPSYS} != "AIX"
PKG_OPTIONS_GROUP.zsh+=		zsh-mem
.endif
PKG_SUPPORTED_OPTIONS+=		${PKG_OPTIONS_GROUP.zsh}
PKG_SUGGESTED_OPTIONS=		${PKG_OPTIONS_GROUP.zsh}

.include "../../mk/bsd.options.mk"

PLIST_VARS=	static pcre

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--disable-dynamic
PLIST.static=		yes
.else
CONFIGURE_ARGS+=	--enable-dynamic
PLIST.dynamic=		yes
.endif

.if !empty(PKG_OPTIONS:Mzsh-mem)
CONFIGURE_ARGS+=	--enable-zsh-mem -enable-zsh-secure-free
.endif

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--enable-pcre
PLIST.pcre=		yes
.  include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if !empty(PKG_OPTIONS:Mzsh-multibyte)
CONFIGURE_ARGS+=	--enable-multibyte
.else
CONFIGURE_ARGS+=	--disable-multibyte
.endif
