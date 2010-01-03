# $NetBSD: Makefile,v 1.6 2010/01/03 00:18:19 jihbed Exp $
#

DISTNAME=	givaro-3.3.2rc1
CATEGORIES=	math
MASTER_SITES=	http://ljk.imag.fr/CASYS/LOGICIELS/givaro/Downloads/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://ljk.imag.fr/CASYS/LOGICIELS/givaro/
COMMENT=	C++ library for arithmetic and algebraic computations
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/givaro-3.3.2
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/examples/${PKGBASE}


post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/FiniteField
	${INSTALL_DATA} ${WRKSRC}/examples/FiniteField/*.C \
		${DESTDIR}${EGDIR}/FiniteField
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/Integer
	${INSTALL_DATA} ${WRKSRC}/examples/Integer/*.C  \
		${DESTDIR}${EGDIR}/Integer
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/Polynomial
	${INSTALL_DATA} ${WRKSRC}/examples/Polynomial/*.C \
		${DESTDIR}${EGDIR}/Polynomial
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/Rational
	${INSTALL_DATA} ${WRKSRC}/examples/Rational/*.C \
		${DESTDIR}${EGDIR}/Rational

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
