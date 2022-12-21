# $NetBSD$

DISTNAME=	influx-cli-2.6.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=influxdata/}
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

DIST_SUBDIR=	influxdata

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/influxdata/influx-cli/
COMMENT=	CLI for managing resources in InfluxDB v2
LICENSE=	mit

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
