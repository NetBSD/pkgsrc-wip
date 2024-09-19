# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	ratpoints-2.1.3
CATEGORIES=	math
MASTER_SITES=	http://www.mathe2.uni-bayreuth.de/stoll/programs/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.mathe2.uni-bayreuth.de/stoll/programs/index.html
COMMENT=	Optimized quadratic sieve algorithm
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	Makefile
SUBST_MESSAGE.paths=	Fixing header search paths.

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/include
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/lib

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratpoints ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ratpoints.h ${DESTDIR}${PREFIX}/include/ratpoints.h
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} libratpoints.a \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ratpoints
	${INSTALL_DATA} ${WRKSRC}/ratpoints-doc.pdf \
		${DESTDIR}${PREFIX}/share/doc/ratpoints

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
