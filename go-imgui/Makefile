# $NetBSD$

DISTNAME=	go-imgui-3.0.0
GITHUB_PROJECT=	imgui-go
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=inkyblackness/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/inkyblackness/imgui-go/
COMMENT=	Go wrapper library for Dear ImGui
LICENSE=	modified-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/inkyblackness/${GITHUB_PROJECT}

USE_LANGUAGES=	c c++

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
