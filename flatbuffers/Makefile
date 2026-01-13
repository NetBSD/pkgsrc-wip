# $NetBSD$

DISTNAME=	flatbuffers-25.12.19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/flatbuffers/
COMMENT=	Memory Efficient Serialization Library
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	CMake/flatbuffers.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
