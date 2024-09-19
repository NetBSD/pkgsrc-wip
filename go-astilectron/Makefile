# $NetBSD$

DISTNAME=	go-astilectron-0.22.3
GITHUB_PROJECT=	go-astilectron
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=asticode/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/asticode/go-astilectron/
COMMENT=	Build cross platform GUI apps with GO and HTML/JS/CSS
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/asticode/${GITHUB_PROJECT}

.include "../../wip/go-astikit/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
