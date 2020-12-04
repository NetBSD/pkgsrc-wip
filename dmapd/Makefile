# $NetBSD: Makefile,v 1.1 2012/12/03 20:56:54 thomasklausner Exp $
#

DISTNAME=	dmapd-0.0.50
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	http://www.flyn.org/projects/dmapd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.flyn.org/projects/dmapd/
COMMENT=	DAAP (iTunes) and DPAP (iPhoto) shares server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	dmapd.pc.in

BUILDLINK_TRANSFORM+=	l:db-4.8:db4-4.8

CONF_FILES+=	share/examples/dmapd/dmapd.conf ${PKG_SYSCONFDIR}/dmapd.conf

INSTALLATION_DIRS+=	share/examples/dmapd

post-install:
	${INSTALL_DATA} ${WRKSRC}/distro/dmapd.conf ${DESTDIR}${PREFIX}/share/examples/dmapd/

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libdmapsharing3/buildlink3.mk"
#.include "../../*/vips/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
