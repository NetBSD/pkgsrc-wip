# $NetBSD$

DISTNAME=	faker-20171103
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	faker
GITHUB_TAG=	9fbc68a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=manveru/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/manveru/faker
COMMENT=	Generate fake data in go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	github.com/manveru/faker

.include "../../devel/go-yaml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
