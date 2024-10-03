# $NetBSD$

DISTNAME=	flamegraph-rs-0.5.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=flamegraph-rs/}
GITHUB_PROJECT=	flamegraph
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/flamegraph-rs/flamegraph/
COMMENT=	Easy flamegraphs for Rust projects and everything else
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.64.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
