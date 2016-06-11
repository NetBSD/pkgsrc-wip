# $NetBSD$

DISTNAME=	keystone-0.9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=keystone-engine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.keystone-engine.org/
COMMENT=	Multi-platform and multi-arch assembler framework
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all

.include "../../mk/bsd.pkg.mk"
