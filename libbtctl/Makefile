# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:24 othyro Exp $
#

DISTNAME=		libbtctl-0.6.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://ftp.gnome.org/pub/gnome/sources/libbtctl/0.6/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://live.gnome.org/GnomeBluetooth
COMMENT=		GObject Bluetooth controller


USE_TOOLS+=		gmake perl
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libbtctl.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/mono/libbtctl/libbtctl-sharp.pc.in

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
