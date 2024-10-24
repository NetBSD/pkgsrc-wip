# $NetBSD$

DISTNAME=	anvil-src-v0.3
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	editors
MASTER_SITES=	http://anvil-editor.net/releases/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	http://anvil-editor.net/
COMMENT=	Plan 9 acme-like editor written in Go
LICENSE=	mit

USE_LANGUAGES=	c

GO_VERSION_REQD+=	123
GO_MODULES_FILES=	${WRKSRC}/anvil/src/anvil/go.mod
GO_BUILD_PATTERN=	.

WRKSRC=	${WRKDIR}/${DISTNAME}/anvil/src/anvil

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV}	\
	    GOPATH=${WRKDIR}/.gopath ${PREFIX}/bin/go123 ${GOFLAGS} build ${GO_BUILD_TAGS} -ldflags=${GO_LDFLAGS:Q}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
