# $NetBSD$

DISTNAME=	go-transcoder-1.1.1
GITHUB_PROJECT=	transcoder
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=floostack/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/floostack/transcoder/
COMMENT=	Transcoding library implementation in Golang
LICENSE=	mit

GO_SRCPATH=     github.com/floostack/transcoder
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
