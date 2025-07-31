# $NetBSD$

DISTNAME=	lean4-4.21.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=leanprover/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leanprover/lean4/
COMMENT=	Programming language for theorem proving
LICENSE=	apache-2.0

DEPENDS+=	cadical-[0-9]*:../../wip/cadical

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

CMAKE_CONFIGURE_ARGS+=	-DUSE_MIMALLOC=no

.include "../../devel/cmake/build.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
