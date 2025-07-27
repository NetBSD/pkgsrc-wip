# $NetBSD$

DISTNAME=	pdfrip-2.0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=mufeedvh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/mufeedvh/pdfrip
COMMENT=	Multi-threaded PDF password cracking utility in Rust
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
