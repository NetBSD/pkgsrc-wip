# $NetBSD$

DISTNAME=	loki-3.5.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://grafana.com/loki
COMMENT=	Like Prometheus, but for logs
LICENSE=	gnu-agpl-v3

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/grafana/loki/pkg/util/build.Branch="" \
			-X github.com/grafana/loki/pkg/util/build.Version=${PKGVERSION_NOREV} \
			-X github.com/grafana/loki/pkg/util/build.Revision="" \
			-X github.com/grafana/loki/pkg/util/build.BuildUser="" \
			-X github.com/grafana/loki/pkg/util/build.BuildDate=""'
GO_BUILD_PATTERN+=	./cmd/loki

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
