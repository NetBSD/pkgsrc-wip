# $NetBSD$

DISTNAME=	git-xargs-0.0.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gruntwork-io/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruntwork-io/git-xargs
COMMENT=	Updates multiple GitHub repositories with a single command
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
