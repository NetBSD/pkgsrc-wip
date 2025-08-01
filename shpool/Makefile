# $NetBSD$

DISTNAME=	shpool-0.8.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=shell-pool/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shell-pool/shpool/
COMMENT=	Session persistence using named shell sessions
LICENSE=	apache-2.0

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
