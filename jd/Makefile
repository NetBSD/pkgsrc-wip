# $NetBSD$

DISTNAME=	jd-1.9.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=josephburnett/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/josephburnett/jd/
COMMENT=	JSON diff and patch
LICENSE=	mit

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
