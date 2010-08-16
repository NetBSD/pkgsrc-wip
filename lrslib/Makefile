# $NetBSD: Makefile,v 1.1.1.1 2010/08/16 13:18:15 jihbed Exp $
#

DISTNAME=	lrslib-042b
CATEGORIES=	math
MASTER_SITES=	http://cgm.cs.mcgill.ca/~avis/C/lrslib/archive/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cgm.cs.mcgill.ca/~avis/C/lrs.html
COMMENT=	Package to enumerate vertices and extreme rays of a convex polyhedron
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=   makefile

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2nash ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/buffer ${DESTDIR}${PREFIX}/bin/lrsbuffer
	${INSTALL_PROGRAM} ${WRKSRC}/fourier ${DESTDIR}${PREFIX}/bin/lrsfourier
	${INSTALL_PROGRAM} ${WRKSRC}/nash ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/redund ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/setupnash ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/setupnash2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lrs ${DESTDIR}${PREFIX}/bin


.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
