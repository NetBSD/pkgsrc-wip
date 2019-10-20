# $NetBSD$

DISTNAME=	libosinfo-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/libosinfo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libosinfo.org/
COMMENT=	Library for querying information from the OSInfo database
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

PKGCONFIG_OVERRIDE+=	osinfo/libosinfo-1.0.pc.in

CHECK_PORTABILITY_SKIP+=	configure

DEPENDS+=		pciids-[0-9]*:../../misc/pciids
CONFIGURE_ARGS+=	--with-pci-ids-path=${PREFIX}/share/pciids
DEPENDS+=		usbids-[0-9]*:../../misc/usbids
CONFIGURE_ARGS+=	--with-usb-ids-path=${PREFIX}/share/usbids

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
