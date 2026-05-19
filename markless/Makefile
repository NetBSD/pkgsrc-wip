# $NetBSD$

DISTNAME=	markless-0.9.29
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jvanderberg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/jvanderberg/markless
COMMENT=	Terminal markdown viewer and editor with image support
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
