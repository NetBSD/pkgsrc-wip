# $NetBSD: Makefile,v 1.12 2013/09/14 23:46:50 asau Exp $

DISTNAME=	atlas3.10.2
PKGNAME=	${DISTNAME:C/atlas/atlas-/}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=math-atlas/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://math-atlas.sourceforge.net/
COMMENT=	Automatically Tuned Linear Algebra Software

CONFLICTS=	lapack-[0-9]*

WRKSRC=		${WRKDIR}/ATLAS
HAS_CONFIGURE=	yes

MAKE_JOBS_SAFE=	no

PKGSRC_FORTRAN=	gfortran
USE_LANGUAGES=	c fortran77
USE_TOOLS+=	gmake

CONFIGURE_DIRS=		obj
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--incdir=${DESTDIR}${PREFIX}/include
CONFIGURE_ARGS+=	--libdir=${DESTDIR}${PREFIX}/lib
CONFIGURE_ARGS+=	-b 32
CONFIGURE_ARGS+=	-t ${MAKE_JOBS}

TEST_TARGET=	check
BUILD_TAGET=	build shared ptshared

pre-configure:
	${RUN} cd ${WRKSRC}; mkdir ${CONFIGURE_DIRS}

.include "../../mk/bsd.pkg.mk"
