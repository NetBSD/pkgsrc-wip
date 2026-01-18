# $NetBSD$

GITHUB_PROJECT=	CuraEngine
GITHUB_TAG=	4.13.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}
STB_IMAGE_H=	stb_image.h
DISTFILES=	${DEFAULT_DISTFILES} ${STB_IMAGE_H}

SITES.${STB_IMAGE_H}	= https://raw.githubusercontent.com/nothings/stb/d5d052c806eee2ca1f858cb58b2f062d9fa25b90/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/CuraEngine/
COMMENT=	Converting 3D models into g-code instructions for 3D printers
LICENSE=	gnu-agpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	311

pre-configure:
	${MKDIR} ${BUILDLINK_DIR}/include/stb
	${LN} -sf ${WRKDIR}/${STB_IMAGE_H} ${BUILDLINK_DIR}/include/stb/

.include "../../devel/protobuf/buildlink3.mk"
.include "../../wip/libArcus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
