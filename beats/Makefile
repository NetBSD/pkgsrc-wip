# $NetBSD$
#

DISTNAME=		beats-1.1.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=elastic/}
GITHUB_PROJECT=		beats
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		filip@joyent.com
HOMEPAGE=		https://www.elastic.co/products/beats
COMMENT=		Data Shippers for Elasticsearch
LICENSE=		apache-2.0

.include "../../lang/go/version.mk"
BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/src/github.com/elastic/beats

EGFILES=		filebeat.template.json filebeat.yml
EGFILES+=		packetbeat.template.json packetbeat.yml
#EGFILES+=		topbeat/topbeat.template.json topbeat/topbeat.yml

.for file in ${EGFILES}
CONF_FILES+=		share/examples/beats/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

PKG_SYSCONFSUBDIR=	beats

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg
BUILD_DIRS=		libbeat packetbeat filebeat # topbeat

BUILD_TARGET=		build

INSTALLATION_DIRS+=	bin share/examples/beats

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filebeat/filebeat ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libbeat/libbeat ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/packetbeat/packetbeat ${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/topbeat ${DESTDIR}${PREFIX}/bin
.for file in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/*/etc/${file} \
		${DESTDIR}${PREFIX}/share/examples/beats
.endfor

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
