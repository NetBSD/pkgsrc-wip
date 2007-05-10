# $NetBSD: Makefile,v 1.4 2007/05/10 15:03:40 emil_s Exp $
#

DISTNAME=		givaro-3.2.6
CATEGORIES=		math
MASTER_SITES=		http://ljk.imag.fr/CASYS/LOGICIELS/givaro/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://ljk.imag.fr/CASYS/LOGICIELS/givaro/
COMMENT=		C++ library for arithmetic and algebraic computations

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

EGDIR=			${PREFIX}/share/examples/${PKGBASE}


post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/FiniteField
	cd ${WRKSRC}/examples/FiniteField && ${INSTALL_DATA} *.C ${EGDIR}/FiniteField
	${INSTALL_DATA_DIR} ${EGDIR}/Integer
	cd ${WRKSRC}/examples/Integer && ${INSTALL_DATA} *.C ${EGDIR}/Integer
	${INSTALL_DATA_DIR} ${EGDIR}/Polynomial
	cd ${WRKSRC}/examples/Polynomial && ${INSTALL_DATA} *.C ${EGDIR}/Polynomial
	${INSTALL_DATA_DIR} ${EGDIR}/Rational
	cd ${WRKSRC}/examples/Rational && ${INSTALL_DATA} *.C ${EGDIR}/Rational


.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
