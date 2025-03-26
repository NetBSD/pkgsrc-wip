# $NetBSD$

GITHUB_TAG=	v5.32.1
DISTNAME=	mattermost-server-${GITHUB_TAG:S,^v,,}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattermost/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://mattermost.com/
COMMENT=	Secure collaboration platform
LICENSE=	mit

GO_BUILD_PATTERN=	-mod=vendor -trimpath ./cmd/mattermost
USE_LANGUAGES=		c # go
CHECK_RELRO_SKIP=	bin/mattermost

WRKSRC=		${WRKDIR}/${DISTNAME:S/-server//}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
