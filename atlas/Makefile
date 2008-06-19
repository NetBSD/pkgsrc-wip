# $NetBSD: Makefile,v 1.2 2008/06/19 19:16:02 asau Exp $

DISTNAME=	atlas3.8.1
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

CONFIGURE_DIRS=		${WRKSRC}/obj
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS+=	--incdir=${DESTDIR}${PREFIX}/include
CONFIGURE_ARGS+=	--libdir=${DESTDIR}${PREFIX}/lib
CONFIGURE_ARGS+=	-v 9 -b 32

TEST_TARGET=	check

pre-configure:
	mkdir ${CONFIGURE_DIRS}

.include "../../mk/bsd.pkg.mk"
