# $NetBSD$

DISTNAME=	go-easyjson-0.7.4.1
GITHUB_PROJECT=	easyjson
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mailru/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mailru/easyjson/
COMMENT=	Fast JSON serializer for golang
LICENSE=	mit

GO_SRCPATH=     github.com/mailru/easyjson
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../wip/go-intern/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
