# $NetBSD: Makefile,v 1.2 2005/04/25 19:49:40 gschwarz Exp $

DISTNAME=	linphone-1.0.1
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/1.0.x/source/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://www.linphone.org
COMMENT=	a SIP-based IP telephony client

BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-osip=${BUILDLINK_PREFIX.libosip2}
CONFIGURE_ARGS+=        --with-speex=${BUILDLINK_PREFIX.speex}
CONFIGURE_ARGS+=	--disable-manual --enable-glib

PKG_SUPPORTED_OPTIONS=	alsa nogui
PKG_OPTIONS_VAR=	PKG_OPTIONS.linphone

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.endif

.if !empty(PKG_OPTIONS:Mnogui)
CONFIGURE_ARGS+=	--enable-gnome_ui=no
PLIST_SUBST+=	GUI="@comment "
.else
PLIST_SUBST+=	GUI=
CONFIGURE_ARGS+=	--enable-gnome_ui=yes
.include "../../x11/gnome-panel/buildlink3.mk"
.endif

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

USE_PERL5+=	build
BUILD_DEPENDS+=	p5-XML-Parser-*:../../textproc/p5-XML-Parser

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
