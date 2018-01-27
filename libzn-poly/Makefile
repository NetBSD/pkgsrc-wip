# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=	zn_poly-0.9
PKGNAME=	libzn-poly-0.9
CATEGORIES=	math
MASTER_SITES=	http://cims.nyu.edu/~harvey/zn_poly/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cims.nyu.edu/~harvey/code/zn_poly/
COMMENT=	Libzn_poly is a C library for polynomial arithmetic in Z/nZ[x]
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	makemakefile.py
SUBST_MESSAGE.paths=	Fixing header search paths.

INCLUDEDIR=	${PREFIX}/include/libzn-poly

INSTALLATION_DIRS=	lib	${INCLUDEDIR}

post-extract:
	${RM} ${WRKSRC}/configure

pre-configure:
	cd ${WRKSRC} && ${PYTHONBIN} makemakefile.py > makefile

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${INCLUDEDIR}
	cd ${WRKSRC}/include && 						\
	for f in *.h; do							\
		${INSTALL_DATA} "$$f" ${DESTDIR}${INCLUDEDIR}; 	\
	done
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/libzn_poly.a ${DESTDIR}${PREFIX}/lib


.include "../../lang/python/extension.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
