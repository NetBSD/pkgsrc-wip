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
GOPATH=		${WRKDIR}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	libexec/mackerel-agent-plugins

do-build:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH}:${GOPATH}/bin ${MAKE_PROGRAM} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${LOWER_OPSYS}/${GOARCH}/* ${DESTDIR}${PREFIX}/libexec/mackerel-agent-plugins

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
