# $NetBSD$

DISTNAME=	makezero-20201207
PKGREVISION=	1
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	makezero
GITHUB_TAG=	7b7cdbb3025a82245521007c82a66e9b1a347ca2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ashanbrown/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ashanbrown/makezero/
COMMENT=	Linter to ensure that slices are not initialized with non-zero length
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
