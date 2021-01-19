# $NetBSD$

DISTNAME=	go-ffmpeg-0.5.0
GITHUB_PROJECT=	goffmpeg
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=xfrr/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/xfrr/goffmpeg/
COMMENT=	FFMPEG wrapper written in GO 
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/xfrr/goffmpeg

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
