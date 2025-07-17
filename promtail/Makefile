# $NetBSD$

DISTNAME=	loki-3.5.2
PKGNAME=	${DISTNAME:S/loki/promtail/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_PROJECT=	loki
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://grafana.com/loki
COMMENT=	Agent to ship logs to Grafana Loki
LICENSE=	gnu-agpl-v3

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/grafana/loki/pkg/util/build.Branch="" \
			-X github.com/grafana/loki/pkg/util/build.Version=${PKGVERSION_NOREV} \
			-X github.com/grafana/loki/pkg/util/build.Revision="" \
			-X github.com/grafana/loki/pkg/util/build.BuildUser="" \
			-X github.com/grafana/loki/pkg/util/build.BuildDate=""'
GO_BUILD_PATTERN+=	./clients/cmd/promtail

# Generate promtail static assets file
pre-build:
	${RUN} cd ${WRKSRC} && \
	${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} generate -x -v ./clients/pkg/promtail/server/ui

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
