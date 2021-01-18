# $NetBSD$

DISTNAME=	go-hidden-20201230
GITHUB_PROJECT=	hidden
GITHUB_TAG=	e66e7f8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=getlantern/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/getlantern/hidden/
COMMENT=	Hide text in text 
LICENSE=	apache-2.0

GO_SRCPATH=	github.com/getlantern/hidden
GO_DIST_BASE=	hidden-${GITHUB_TAG}*

.include "../../wip/go-hex/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
