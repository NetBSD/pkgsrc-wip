# $NetBSD$

DISTNAME=	ntfy-2.28.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=binwiederhier/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	tallirishllama@gmail.com
HOMEPAGE=	https://github.com/binwiederhier/ntfy/
COMMENT=	Push notification service
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

MAKE_ENV+=	"CGO_ENABLED=1"

pre-build:
	mkdir -p ${WRKSRC}/dist/ntfy_server ${WRKSRC}/server/docs ${WRKSRC}/server/site
	touch ${WRKSRC}/server/docs/index.html ${WRKSRC}/server/site/app.html

GO_BUILD_PATTERN+=	-tags sqlite_omit_load_extension,osusergo,netgo
GO_BUILD_PATTERN+=	-ldflags "-linkmode=external -extldflags=-static -s -w -X main.version=${PKGVERSION_NOREV}"

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"

.include "../../mk/bsd.pkg.mk"
