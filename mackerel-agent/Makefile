# $NetBSD$

DISTNAME=	mackerel-agent-0.47.2
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mackerelio/}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/mackerelio/mackerel-agent/
COMMENT=	The mackerel-agent is an agent program to mackerel.io
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar
GO_SRCPATH=	github.com/mackerelio/${DISTNAME}
WRKSRC=		${WRKDIR}/src/${GO_SRCPATH}
GOPATH=		${WRKDIR}
EXTRACT_DIR=	${WRKDIR}/src/github.com/mackerelio
USE_TOOLS+=	gmake perl
BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

INSTALLATION_DIRS+=	bin share/examples/mackerel-agent

pre-extract:
	cd ${WRKDIR} && ${MKDIR} ${EXTRACT_DIR}

do-build:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} build

do-test:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/mackerel-agent ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf ${DESTDIR}${PREFIX}/share/examples/mackerel-agent

.include "../../mk/bsd.pkg.mk"
