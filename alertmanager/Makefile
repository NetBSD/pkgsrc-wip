# $NetBSD$

DISTNAME=	alertmanager-0.34.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prometheus.io/
COMMENT=	Prometheus Alertmanager
LICENSE=	apache-2.0

DISTFILES=	${DEFAULT_DISTFILES}

FE_DISTNAME=			alertmanager-web-ui-0.34.0.tar.gz
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		https://github.com/prometheus/alertmanager/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKSRC}/ui/app
EXTRACT_ONLY=			${DEFAULT_DISTFILES} ${FE_DISTNAME}

GOFLAGS+=		-ldflags " \
			-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
			-X github.com/prometheus/common/version.Revision=${PKGVERSION} \
			-X github.com/prometheus/common/version.Branch=pkgsrc \
			-X github.com/prometheus/common/version.BuildUser=pkgsrc@localhost \
			-X github.com/prometheus/common/version.BuildDate=${:!date +%Y%m%d-%H:%M:%S!}" \
			-tags netgo

GO_BUILD_PATTERN+=	./cmd/alertmanager
GO_BUILD_PATTERN+=	./cmd/amtool

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
