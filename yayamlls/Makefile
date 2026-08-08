# $NetBSD$

DISTNAME=	yayamlls-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=home-operations/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/home-operations/yayamlls/
COMMENT=	YAML language server in Go
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c

# as of 0.2.0:
# 1 test failure, see
# https://github.com/home-operations/yayamlls/issues/150

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
