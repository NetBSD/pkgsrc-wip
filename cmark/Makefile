# $NetBSD$

DISTNAME=	cmark-0.24.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgm/}

MAINTAINER=	pkgsrc-users@NetBSD.rog
HOMEPAGE=	${MASTER_SITE_GITHUB:=jgm/cmark/}
COMMENT=	CommonMark parsing and rendering library and program in C
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libcmark.pc.in

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
