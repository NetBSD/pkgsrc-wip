# $NetBSD$

DISTNAME=	consul-0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.consul.io/
COMMENT=	Tool for service discovery, monitoring and configuration
LICENSE=	mpl-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES+=	${DEFAULT_DISTFILES} ${DISTNAME}-deps.tar.gz
SITES.${DISTNAME}-deps.tar.gz=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/

WRKSRC=		${WRKDIR}/src/github.com/hashicorp/consul

.include "../../lang/go/version.mk"

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

USE_LANGUAGES=		c
USE_TOOLS+=		bash gmake

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

deps: extract
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} deps ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -o bin/consul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/consul ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
