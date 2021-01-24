# $NetBSD$

DISTNAME=	tomb.v1-20140924
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	tomb
PKGREVISION=	1
GITHUB_TAG=	dd632973f1e7218eb1089048e0798ec9ae7dceb8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-tomb/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/go-tomb/tomb
COMMENT=	Helps with clean goroutine termination in the Go language
LICENSE=	modified-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/go-tomb/tomb

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
