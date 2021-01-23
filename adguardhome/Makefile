# $NetBSD$


.include "go-modules.mk"

GITHUB_PROJECT=	AdGuardHome
GITHUB_TAG=	v0.104.3
DISTNAME=	v0.104.3
PKGNAME=	adguardhome-${DISTNAME:S,^v,,}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdguardTeam/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bbartlomiej@gmail.com
HOMEPAGE=	https://github.com/AdguardTeam/AdGuardHome/
COMMENT=	Free and open source, network-wide ads & trackers blocking DNS server
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/adguardhome-0.104.3
USE_LANGUAGES=	# none

#BUILD_DEPENDS+= npm>=6.14:../../lang/npm
#BUILD_DEPENDS+=	nodejs>=10.16:../../lang/nodejs

PKG_SYSCONFSUBDIR=	adguardhome

.include "../../lang/go/go-vars.mk"

PREPEND_PATH+=	${WRKDIR}/.gopath/bin
MAKE_ENV+=      GO111MODULE=on GOPATH=${WRKDIR}/.gopath GOPROXY=file://${WRKDIR}/.goproxy
MAKE_ENV+=      GOCACHE=${WRKDIR}/.cache/go-build

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} generate ./...
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} build -ldflags="-s -w -X main.version=${DISTNAME:S,^v,,} -X main.channel=release -X main.goarm=${GOARM}"

.PHONY: generate-client
generate-client:
	# You need to have npm >=6.14:../../lang/npm and
	# nodejs>=10.16:../../lang/nodejs to build this part. Next it has to be
	# uploaded to distfile location on pkgsrc distfile server.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm --prefix client run build-prod
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm --prefix client ci

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
