# $NetBSD$

DISTNAME=	hawk-v0.9
PKGNAME=	${DISTNAME:S,-v,-scheme-,}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=djwatson/}
GITHUB_PROJECT=	hawk
GITHUB_RELEASE=	v0.9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://djwatson.github.io/hawk/
COMMENT=	Scheme jit that makes code fly!
# not use about this, some third party files are "do as you please"
# and some third party files have no explicit copyright
LICENSE=	mit AND modified-bsd

# needs [[musttail]]
#GCC_REQD=		15
PKGSRC_COMPILER=	clang

USE_LANGUAGES+=		c c++
CMAKE_CONFIGURE_ARGS+=	-DBOOTSTRAP=ON

NOT_PAX_MPROTECT_SAFE+=	bin/hawk

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_DEPMETHOD.Gauche=	build
.include "../../lang/gauche/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
