# $NetBSD$

DISTNAME=	go-config-0.13.0
GITHUB_PROJECT=	config
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=revel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/revel/config/
COMMENT=	Configuration file parser for INI format
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/revel/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
