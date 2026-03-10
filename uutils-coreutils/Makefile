# $NetBSD$

DISTNAME=	coreutils-0.7.0
PKGNAME=	uutils-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=uutils/}
GITHUB_PROJECT=	coreutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uutils.github.io/coreutils/
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
LICENSE=	mit

RUST_REQ=	1.88.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
