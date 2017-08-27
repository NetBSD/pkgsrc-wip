# $NetBSD$

GITHUB_TAG=	v1.3.0
DISTNAME=	${GITHUB_TAG}
DIST_SUBDIR=	go-flags
PKGNAME=	${DIST_SUBDIR}-${GITHUB_TAG:S/v//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jessevdk/}
GITHUB_PROJECT=	go-flags

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/jessevdk/go-flags
COMMENT=	Go command line option parser
LICENSE=	modified-bsd

REPLACE_BASH+=	check_crosscompile.sh

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	go-flags-${GITHUB_TAG:S/v//}
GO_SRCPATH=	github.com/jessevdk/go-flags

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
