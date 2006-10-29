# $NetBSD: Makefile,v 1.13 2006/10/29 08:32:46 shattered Exp $

DISTNAME=	linphone-1.3.5
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/1.3.x/source/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.linphone.org/
COMMENT=	SIP-based IP telephony client

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake intltool perl pkg-config
USE_DIRS+=	gnome2-1.6 xdg-1.4
USE_LIBTOOL=	YES
USE_GNU_READLINE=	yes # rl_hook_func_t et al.
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-osip=${BUILDLINK_PREFIX.libosip2}
CONFIGURE_ARGS+=	--with-speex=${BUILDLINK_PREFIX.speex}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/linphone
CONFIGURE_ARGS+=	--disable-manual --enable-glib

PKG_SUPPORTED_OPTIONS=	alsa inet6 linphone-gui
PKG_SUGGESTED_OPTIONS=	linphone-gui
PKG_OPTIONS_VAR=	PKG_OPTIONS.linphone

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.endif

.if empty(PKG_OPTIONS:Mlinphone-gui)
CONFIGURE_ARGS+=	--enable-gnome_ui=no
PLIST_SUBST+=	GUI="@comment "
.else
PLIST_SUBST+=	GUI=
CONFIGURE_ARGS+=	--enable-gnome_ui=yes
.include "../../x11/gnome-panel/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDSP_NAME="\"${DEVOSSAUDIO}\""

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../wip/speex-devel/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
