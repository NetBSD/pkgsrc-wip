# $NetBSD$

.include "../../wip/libjxl/Makefile.common"

PKGNAME=	${DISTNAME:S/lib/gimp-/g}
COMMENT=	JpegXL Gimp plugin

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CONFIGURE_DIRS=	plugins/gimp
BUILD_DIRS=	plugins/gimp

.include "../../graphics/gimp/buildlink3.mk"
.include "../../wip/libjxl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
