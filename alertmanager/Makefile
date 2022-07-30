# $NetBSD$

DISTNAME=	alertmanager-0.24.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prometheus.io/
COMMENT=	Prometheus Alertmanager
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
			-X github.com/prometheus/common/version.Revision= \
			-X github.com/prometheus/common/version.Branch= \
			-X github.com/prometheus/common/version.BuildUser= \
			-X github.com/prometheus/common/version.BuildDate='
GO_BUILD_PATTERN+=	./cmd/alertmanager
GO_BUILD_PATTERN+=	./cmd/amtool

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
