# $NetBSD$

DISTNAME=	shoutrrr-0.6.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=containrrr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://containrrr.dev/shoutrrr/
COMMENT=	Notification library and CLI for gophers and their furry friends
LICENSE=	mit

#GO_BUILD_PATTERN+=	-ldflags ' \
#			-X github.com/trufflesecurity/trufflehog/v3/pkg/version.BuildVersion=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./shoutrrr

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
