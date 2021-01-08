# $NetBSD$

DISTNAME=	goreferrer-20181106
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	goreferrer
GITHUB_TAG=	ec9c9a553398739f0dcf817e0ad5e01c4e7dcd08
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Shopify/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kiaderouiche/goreferrer/
COMMENT=	Analyzes and classifies different kinds of referrer URLs
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/Shopify/${GITHUB_PROJECT}

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
