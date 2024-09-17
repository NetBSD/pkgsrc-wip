# $NetBSD$

DISTNAME=	pueue-3.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nukesor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nukesor/pueue/
COMMENT=	Manage your shell commands
LICENSE=	mit

USE_LANGUAGES=		c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
