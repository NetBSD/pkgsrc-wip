# $NetBSD$

DISTNAME=	bandwidthmon-0.1.14.20251211_161101_545599
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cumulus13/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cumulus13/bandwidthmon/
COMMENT=	Real-time network bandwidth monitor
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.86.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
