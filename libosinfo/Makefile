# $NetBSD$

DISTNAME=	libosinfo-1.9.0
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/libosinfo/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libosinfo.org/
COMMENT=	Library for querying information from the OSInfo database
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	osinfo/libosinfo-1.0.pc.in

DEPENDS+=		pciids-[0-9]*:../../misc/pciids
MESON_ARGS+=		-Dwith-pci-ids-path=${PREFIX}/share/pciids
DEPENDS+=		usbids-[0-9]*:../../misc/usbids
MESON_ARGS+=		-Dwith-usb-ids-path=${PREFIX}/share/usbids

.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
