# $NetBSD$

DISTNAME=	cli-0.37.0
PKGNAME=	tektoncd-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tektoncd/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	tekton

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tekton.dev/vault/cli-main/
COMMENT=	Command line client for interacting with Tekton components
LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

GO_VERSION_REQD+=	122

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/tkn ${DESTDIR}${PREFIX}/bin/tkn

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
