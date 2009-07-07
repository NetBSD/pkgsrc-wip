# $NetBSD: options.mk,v 1.3 2009/07/07 09:58:14 tnn2 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.firefox35
PKG_SUPPORTED_OPTIONS=	debug official-mozilla-branding mozilla-jemalloc

PLIST_VARS+=		jemalloc branding

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
. if ${OPSYS} == "SunOS"
PLIST.jemalloc=		yes
. endif
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=	--enable-official-branding
PLIST.branding=		yes
LICENSE=		mozilla-trademark-license
RESTRICTED=		Trademark holder prohibits distribution of modified versions.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif
