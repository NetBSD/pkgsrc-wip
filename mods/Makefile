# $NetBSD$

DISTNAME=	mods-1.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=charmbracelet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/charmbracelet/mods
COMMENT=	AI on the command line
LICENSE=	mit

#GO_BUILD_PATTERN+=	-ldflags ' \
#			-X sigs.k8s.io/release-utils/version.gitVersion=${GITHUB_TAG}'
#GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
