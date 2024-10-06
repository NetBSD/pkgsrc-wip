# $NetBSD$

DISTNAME=	inferno-0.11.21
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonhoo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jonhoo/inferno/
COMMENT=	Rust port of FlameGraph
LICENSE=	cddl-1.0

.include "cargo-depends.mk"

RUST_REQ=	1.71.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
