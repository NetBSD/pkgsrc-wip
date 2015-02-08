# $NetBSD: Makefile,v 1.13 2015/02/08 21:19:52 jihbed Exp $

DISTNAME=	givaro-3.8.0
CATEGORIES=	math
MASTER_SITES=	https://forge.imag.fr/frs/download.php/592/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://ljk.imag.fr/CASYS/LOGICIELS/givaro/
COMMENT=	C++ library for arithmetic and algebraic computations
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
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

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
