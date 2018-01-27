# $NetBSD$

DISTNAME=	mackerel-agent-plugins-0.43.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mackerelio/}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/mackerelio/mackerel-agent-plugins
COMMENT=	This is the official plugin pack for mackerel-agent
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar
GO_SRCPATH=	github.com/mackerelio/${DISTNAME}
WRKSRC=		${WRKDIR}/src/${GO_SRCPATH}
GOPATH=		${WRKDIR}
EXTRACT_DIR=	${WRKDIR}/src/github.com/mackerelio
USE_TOOLS+=	gmake perl
BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

INSTALLATION_DIRS+=	bin

ARCH=`${UNAME} -m`

pre-extract:
	cd ${WRKDIR} && ${MKDIR} ${EXTRACT_DIR}

do-build:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} build

do-test:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${LOWER_OPSYS}/${ARCH}/* ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
