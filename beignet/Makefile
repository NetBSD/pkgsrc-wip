# $NetBSD$

DISTNAME=	beignet-1.3.2-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	graphics
MASTER_SITES=	https://01.org/sites/default/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://01.org/beignet/
COMMENT=	OpenCL implementation for Intel GPUs
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/Beignet-${PKGVERSION_NOREV}-Source

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DOCLICD_COMPAT=0

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
