# $NetBSD$

DISTNAME=	go-uilive-0.0.4
GITHUB_PROJECT=	uilive
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=gosuri/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gosuri/uilive/
COMMENT=	Uilive is a go library for updating terminal output in realtime
LICENSE=	mit

GO_DIST_BASE=	uilive-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gosuri/uilive

.include "../../devel/go-errors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
