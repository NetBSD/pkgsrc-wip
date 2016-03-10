# $NetBSD$

DISTNAME=	klayout-0.24.5
CATEGORIES=	cad
MASTER_SITES=	http://www.klayout.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.klayout.org/downloads/
COMMENT=	Simple GDS and OASIS file viewer and Editor
LICENSE=	gnu-gpl-v2

BROKEN=		Shared library linking fails, see TODO, thank you.

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CFLAGS+=	-I${PREFIX}/include/python${PYVERSUFFIX}
LD_LIBRARY_PATH=${PREFIX}/lib
NO_CONFIGURE=	yes

SUBST_CLASSES+= 	rpath
SUBST_MESSAGE.rpath=	Add COMPILER_RPATH_FLAG and PREFIX to NetBSD specific config file
SUBST_FILES.rpath+=	config/Makefile.conf.netbsd-32-gcc-release
SUBST_STAGE.rpath=	post-patch
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG PREFIX

do-build:
	(cd ${WRKSRC}; sh build.sh -python python${PYVERSSUFFIX} -qt ${PREFIX}/qt4)

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
# libQtDesigner
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
