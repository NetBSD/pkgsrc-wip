# $NetBSD: Makefile,v 1.1 2015/09/06 14:35:45 slitvinov Exp $
#

DISTNAME=	gerris-snapshot
SNAPDATE=	131206
PKGNAME=	gerris-0.9.2.${SNAPDATE}
CATEGORIES=	math
MASTER_SITES=	http://gerris.dalembert.upmc.fr/gerris/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://gfs.sourceforge.net/wiki/index.php/Main_Page
COMMENT=	Software the solution of the PDE describing fluid flow
WRKSRC=		${WRKDIR}/gerris-snapshot-${SNAPDATE}
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config pax
USE_LANGUAGES=	c fortran77

PKGCONFIG_OVERRIDE+=	src/gerris2D.pc.in
#PKGCONFIG_OVERRIDE+=	src/gerris2D3.pc.in
PKGCONFIG_OVERRIDE+=	src/gerris3D.pc.in

REPLACE_PYTHON+=	doc/examples/gfs2doc.in

#DOCDIR=	${PREFIX}/share/doc/gerris/html

# post-install:
# 	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
# 	cd ${WRKSRC}/doc/html && pax -rw -pp . \
# 		${DESTDIR}${PREFIX}/share/doc/gerris/html
# 	${INSTALL_DATA} ${WRKSRC}/doc/tutorial/tutorial.pdf \
# 		${DESTDIR}${PREFIX}/share/doc/gerris
# 	${INSTALL_DATA} ${WRKSRC}/doc/faq/faq.pdf \
# 		${DESTDIR}${PREFIX}/share/doc/gerris

TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/modules/
TEST_TARGET=		check

.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../wip/gts-snapshot/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
