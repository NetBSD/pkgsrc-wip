# $NetBSD$

DISTNAME=	mackerel-agent-0.51.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mackerelio/}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/mackerelio/mackerel-agent/
COMMENT=	Client software for Mackerel.io
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar
GO_SRCPATH=	github.com/mackerelio/${DISTNAME}
GOPATH=		${WRKDIR}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	bin share/examples/mackerel-agent

EGDIR=        ${PREFIX}/share/examples/mackerel-agent
CONF_FILES=   ${EGDIR}/mackerel-agent.sample.conf ${PKG_SYSCONFDIR}/mackerel-agent.sample.conf

do-build:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} build

do-test:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/mackerel-agent ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf ${DESTDIR}${EGDIR}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
