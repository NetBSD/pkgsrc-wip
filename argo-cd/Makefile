# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	argo-cd-2.9.18
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=argoproj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/argoproj/argo-cd/
COMMENT=	Command line tool for interacting with Argo CD
LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${DISTNAME}

BUILD_TARGET+=	cli-local

do-build:
	${RUN} cd ${WRKSRC} && \
	${_ULIMIT_CMD} \
	${PKGSRC_SETENV} \
		${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			${BUILD_TARGET}


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/argocd ${DESTDIR}${PREFIX}/bin/argocd

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
