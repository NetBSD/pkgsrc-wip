# $NetBSD: Makefile,v 1.6 2009/10/14 20:17:34 asau Exp $

ATLAS_VERSION=	3.9.15

DISTNAME=	atlas${ATLAS_VERSION}
PKGNAME=	atlas-${ATLAS_VERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=math-atlas/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://math-atlas.sourceforge.net/
COMMENT=	Automatically Tuned Linear Algebra Software

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ATLAS
HAS_CONFIGURE=	yes

MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c fortran

CONFIGURE_DIRS=		obj
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--incdir=${DESTDIR}${PREFIX}/include
CONFIGURE_ARGS+=	--libdir=${DESTDIR}${PREFIX}/lib
CONFIGURE_ARGS+=	-b 32

TEST_TARGET=	check

pre-configure:
	${RUN} cd ${WRKSRC}; mkdir ${CONFIGURE_DIRS}

.include "../../mk/bsd.pkg.mk"
