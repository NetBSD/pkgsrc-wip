# $NetBSD$

DISTNAME=	bun-1.4.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=oven-sh/}
CATEGORIES=	lang
GITHUB_TAG=	bun-v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://bun.com/
COMMENT=	Incredibly fast JavaScript runtime, bundler, test runner, and package manager
LICENSE=	mit AND gnu-lgpl-v2

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
