# $NetBSD$

DISTNAME=	termdbms-0.3-alpha
PKGNAME=	${DISTNAME:S/-alp/alp/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mathaou/}
GITHUB_TAG=	v0.3-alpha

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mathaou/termdbms/
COMMENT=	TUI for viewing and editing database files
LICENSE=	mit

USE_LANGUAGES=	# none

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
