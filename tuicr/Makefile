# $NetBSD$

DISTNAME=	tuicr-0.23.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=agavra/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agavra/tuicr/
COMMENT=	TUI GitHub or GitLab review
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
