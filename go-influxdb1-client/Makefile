# $NetBSD$

DISTNAME=	influxdb1-client-20200827
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	influxdb1-client
GITHUB_TAG=	b269163b24ab8e62026d13a92aa988a7389c3b4e
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=influxdata/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/influxdata/influxdb1-client
COMMENT=	The old clientv2 for InfluxDB 1.x
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/influxdata/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
