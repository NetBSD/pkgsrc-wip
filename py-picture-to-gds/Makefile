# $NetBSD$

DISTNAME=	master
PKGNAME=	${PYPKGPREFIX}-picture-to-gds-0.1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ourfool/picture-to-gds/archive/}

EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.com
HOMEPAGE=	https://github.com/ourfool/picture-to-gds/
COMMENT=	Python script to convert image files to GDSII files
LICENSE=	gnu-gpl-v3

DEPENDS+=	py*-gdsCAD-[0-9]*:../../cad/py-gdscad
DEPENDS+=	opencv-[0-9]*:../../graphics/opencv

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/picture-to-gds-${DISTNAME}
INSTALL_DIR=	${PREFIX}/bin
SHARE_DIR=	${PREFIX}/picture-to-gds/share
USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

do-install:
	( cd ${WRKSRC};\
	${MKDIR}                   ${DESTDIR}${INSTALL_DIR};\
	${MKDIR}                   ${DESTDIR}${SHARE_DIR};\
	${INSTALL} picToGDS.py     ${DESTDIR}${INSTALL_DIR};\
	${INSTALL} LICENSE         ${DESTDIR}${SHARE_DIR};\
	${INSTALL} README.md       ${DESTDIR}${SHARE_DIR};\
	)

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"

.include "../../mk/bsd.pkg.mk"
