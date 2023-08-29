# $NetBSD$

DISTNAME=		joker-1.3.0
PKGVERSION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=candid82/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		kevin.bloom@posteo.net
HOMEPAGE=		https://joker-lang.org/
COMMENT=		A small dialect of Clojure and Clojure(Script) linter.
LICENSE=		epl-v1.0

INSTALLATION_DIRS+=	bin

GO_BUILD_PATTERN=	.

pre-build:
	ln -sf ${GO} ${BUILDLINK_DIR}/bin/go
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
	    GOPATH=${WRKDIR}/.gopath ${GO} generate ./...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
