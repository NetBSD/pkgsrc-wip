# $NetBSD$

DISTNAME=	divoom-0.1.42
CATEGORIES=	net graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=r12f/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/r12f/divoom/
COMMENT=	Rust Library for controlling divoom devices that support REST APIs
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
