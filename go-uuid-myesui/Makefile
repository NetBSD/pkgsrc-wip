# $NetBSD$

DISTNAME=	go-uuid-myesui-1.0.0
GITHUB_PROJECT=	uuid
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=myesui/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/myesui/uuid/
COMMENT=	Go RFC4122 UUID implementation
LICENSE=	mit

GO_SRCPATH=	github.com/myesui/uuid
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
