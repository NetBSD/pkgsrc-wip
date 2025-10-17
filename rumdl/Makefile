# $NetBSD$

DISTNAME=	rumdl-0.0.162
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rvben/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rvben/rumdl/
COMMENT=	Markdown Linter
LICENSE=	mit

RUST_REQ=	1.89.0
USE_LANGUAGES+=	c c++

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
