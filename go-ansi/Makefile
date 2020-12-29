# $NetBSD$

DISTNAME=	go-ansi-20200706
GITHUB_PROJECT=	ansi
GITHUB_TAG=	d51e80ef957dba7f19388ca64afefbd5a096af30
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgutz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mgutz/ansi
COMMENT=	Fast library to create ANSI colored strings and codes
LICENSE=	mit

GO_SRCPATH=	github.com/mgutz/ansi
GO_DIST_BASE=	ansi-${GITHUB_TAG}

.include "../../devel/go-colorable/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
