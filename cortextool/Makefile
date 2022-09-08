# $NetBSD$

DISTNAME=	cortex-tools-0.10.7
PKGNAME=	${DISTNAME:S/cortex-tools/cortextool/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_PROJECT=	cortex-tools
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grafana/cortex-tools#cortextool
COMMENT=	Tool to interacts with Cortex APIs and backend storage components
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/grafana/cortex-tools/pkg/version.Version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/cortextool

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
