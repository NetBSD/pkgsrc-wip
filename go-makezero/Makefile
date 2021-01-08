# $NetBSD$

DISTNAME=	makezero-20201207
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	makezero
GITHUB_TAG=	7b7cdbb3025a82245521007c82a66e9b1a347ca2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ashanbrown/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ashanbrown/makezero/
COMMENT=	Linter to ensure that slices are not initialized with non-zero length
LICENSE=	apache-2.0

GO_SRCPATH=	github.com/ashanbrown/makezero
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
