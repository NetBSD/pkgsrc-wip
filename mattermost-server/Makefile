# $NetBSD$

GITHUB_TAG=	v5.21.0
DISTNAME=	mattermost-server-${GITHUB_TAG:S,^v,,}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattermost/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://mattermost.com/
COMMENT=	TODO: Short description of the package
LICENSE=	mit

GO_BUILD_PATTERN= -mod=vendor -trimpath ./cmd/mattermost
USE_LANGUAGES=	c # go
CHECK_RELRO_SKIP=	bin/mattermost

.include "../../wip/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
