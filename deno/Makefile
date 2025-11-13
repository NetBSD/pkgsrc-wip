# $NetBSD$

DISTNAME=	deno-2.5.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=denoland/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/denoland/deno/
COMMENT=	Modern runtime for JavaScript and TypeScript
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

USE_LANGUAGES=	c c++

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
