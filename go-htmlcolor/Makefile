# $NetBSD$

DISTNAME=	htmlcolor-20190529
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	htmlcolor
GITHUB_TAG=	c589f58466d094cbc1f1454770545793cd8e7552
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=x86kernel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/x86kernel/htmlcolor
COMMENT=	Html syntax highlighter for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/x86kernel/htmlcolor

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-color/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
