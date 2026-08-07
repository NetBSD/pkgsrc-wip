# $NetBSD$

DISTNAME=	mcfly-0.9.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cantino/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cantino/mcfly/
COMMENT=	Intelligent ^R search through your shell history
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
