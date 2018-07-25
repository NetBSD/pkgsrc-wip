# $NetBSD$

DISTNAME=	mackerel-agent-plugins-0.51.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mackerelio/}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/mackerelio/mackerel-agent-plugins
COMMENT=	Plugin pack for mackerel-agent
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar
GO_SRCPATH=	github.com/mackerelio/${DISTNAME}
GOPATH=		${WRKDIR}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	libexec/mackerelagent

do-build:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH:Q}:${GOPATH}/bin ${MAKE_PROGRAM} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${LOWER_OPSYS}/${GOARCH}/* \
		${DESTDIR}${PREFIX}/libexec/mackerelagent

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
