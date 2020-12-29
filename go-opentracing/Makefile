# $NetBSD$

DISTNAME=	go-opentracing-1.2.0
GITHUB_PROJECT=	opentracing-go
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=opentracing/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://opentracing.io/
COMMENT=	OpenTracing API for Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/opentracing/opentracing-go

.include "../../devel/go-testify/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
