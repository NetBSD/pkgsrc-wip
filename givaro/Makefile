# $NetBSD: Makefile,v 1.10 2010/11/05 09:59:36 emil_s Exp $
#

DISTNAME=	givaro-3.3.3
CATEGORIES=	math
MASTER_SITES=	http://ljk.imag.fr/CASYS/LOGICIELS/givaro/Downloads/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://ljk.imag.fr/CASYS/LOGICIELS/givaro/
COMMENT=	C++ library for arithmetic and algebraic computations
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}

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
