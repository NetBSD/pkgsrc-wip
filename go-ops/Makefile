# $NetBSD$

DISTNAME=	go-ops-20200503
GITHUB_PROJECT=	ops
GITHUB_TAG=	8476b16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=getlantern/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/getlantern/ops
COMMENT=	Track success or failure of operations in code
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	github.com/getlantern/ops

.include "../../wip/go-context/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
