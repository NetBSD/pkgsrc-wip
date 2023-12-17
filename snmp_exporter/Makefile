# $NetBSD$

DISTNAME=	snmp_exporter-0.25.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/snmp_exporter/
COMMENT=	SNMP Exporter for Prometheus
LICENSE=	apache-2.0

# go link -r?
# go link -extldflags?
#GO_BUILD_PATTERN+=	-ldflags '-r ${PREFIX}/lib'
#GO_BUILD_PATTERN+=	./...

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
