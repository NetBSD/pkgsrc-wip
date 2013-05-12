# $NetBSD: options.mk,v 1.7 2013/05/12 06:48:42 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.firefox
PKG_SUPPORTED_OPTIONS=	official-mozilla-branding

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nobranding
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=	--enable-official-branding
LICENSE=		mozilla-trademark-license
RESTRICTED=		Trademark holder prohibits distribution of modified versions.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.else
PLIST.nobranding=	yes
.endif
