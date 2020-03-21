# $NetBSD$

GITHUB_PROJECT=	go-properties-map
GITHUB_TAG=	ad37f0cfeff29fadeabe6b2f7f852d8db1fb5c41
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}

PKGREVISION=	7
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arduino/go-properties-map
COMMENT=	TODO: Short description of the package
LICENSE=	mit
USE_LANGUAGES=	go

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/arduino/go-properties-map

DEPENDS+=	go-paths-helper>=0:../../wip/go-paths-helper




.include "../../lang/go/go-package.mk"

.include "../../wip/go-paths-helper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
