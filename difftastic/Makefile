# $NetBSD$

DISTNAME=	difftastic-0.13.0
GITHUB_TAG=	${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

USE_LANGUAGES+=		c c++17
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/difft ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../mk/bsd.prefs.mk"
PKGSRC_COMPILER=clang
CLANGBASE=${PREFIX}
.include "../../lang/llvm/buildlink3.mk"
BUILDLINK_DEPMETHOD.llvm=build
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=build

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
