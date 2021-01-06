# $NetBSD$

DISTNAME=	go-audio-1.0.0
GITHUB_PROJECT=	audio
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-audio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/go-audio/audio/
COMMENT=	Common interface to analyze and/or process audio data 
LICENSE=	apache-2.0

GO_SRCPATH=     github.com/go-audio/audio
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
