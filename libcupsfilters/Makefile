# $NetBSD$

GITHUB_PROJECT=	libcupsfilters
DISTNAME=	libcupsfilters-2.0.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_RELEASE=	2.0.0

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/libcupsfilters/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFLICTS=        cups-filters<2.0.0

PKGCONFIG_OVERRIDE+=	libcupsfilters.pc.in

.include "options.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
#BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
