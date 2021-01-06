# $NetBSD$

DISTNAME=	go-mp3-0.3.1
GITHUB_PROJECT=	go-mp3
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hajimehoshi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hajimehoshi/go-mp3/
COMMENT=	MP3 decoder in pure Go
LICENSE=	apache-2.0

GO_SRCPATH=     github.com/hajimehoshi/go-mp3
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
