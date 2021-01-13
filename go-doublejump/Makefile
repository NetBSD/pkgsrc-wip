# $NetBSD$

DISTNAME=	go-doublejump-20200330
GITHUB_PROJECT=	doublejump
GITHUB_TAG=	e4ea8bd
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dgryski/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/edwingeng/doublejump
COMMENT=	Revamped Google's jump consistent hash
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	github.com/edwingeng/doublejump

.include "../../wip/go-jump/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
