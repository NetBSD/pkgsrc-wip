# $NetBSD: Makefile,v 1.2 2015/06/25 12:41:09 fhajny Exp $

DISTNAME=	OCE-0.17.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=tpaviot/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/tpaviot/oce/
COMMENT=	Open CASCADE Community Edition
LICENSE=	gnu-lgpl-v2.1

GITHUB_TAG=	${DISTNAME}

WRKSRC=		${WRKDIR}/oce-${DISTNAME}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CHECK_PORTABILITY_SKIP+=	samples/qt/*

# mk/configure/cmake.mk disable rpath handling
# but we need it for a lib subpath
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/oce

CMAKE_ARGS+=	-DOCE_INSTALL_PREFIX:PATH=${PREFIX}

##MAKE_FLAGS+=	VERBOSE=1

LIBS.SunOS+=	-lresolv

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
