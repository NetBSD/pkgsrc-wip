# $NetBSD: Makefile,v 1.7 2005/11/19 22:25:26 gschwarz Exp $

DISTNAME=	linphone-1.0.1
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/1.0.x/source/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://www.linphone.org
COMMENT=	SIP-based IP telephony client

BUILD_DEPENDS+= p5-XML-Parser-*:../../textproc/p5-XML-Parser

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl
USE_LIBTOOL=	YES
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-osip=${BUILDLINK_PREFIX.libosip2}
CONFIGURE_ARGS+=        --with-speex=${BUILDLINK_PREFIX.speex}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/linphone
CONFIGURE_ARGS+=	--disable-manual --enable-glib

PKG_SUPPORTED_OPTIONS=	alsa inet6 linphone-gui
PKG_OPTIONS_VAR=	PKG_OPTIONS.linphone
PKG_DEFAULT_OPTIONS+=	linphone-gui

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

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
