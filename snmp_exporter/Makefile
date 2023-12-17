# $NetBSD$

DISTNAME=	snmp_exporter-0.25.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/snmp_exporter/
COMMENT=	SNMP Exporter for Prometheus
LICENSE=	apache-2.0

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e 's|-L/usr/local/lib|-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib|'
SUBST_SED.path+=	-e 's,/usr/local,${PREFIX},'
SUBST_FILES.path+=	generator/net_snmp.go
SUBST_MESSAGE.path=	Fixing path to includes and libraries.
SUBST_STAGE.path=	pre-configure

INSTALLATION_DIRS+=	share/doc/snmp_exporter

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/snmp_exporter

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
