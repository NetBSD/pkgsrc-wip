# $NetBSD$

GITHUB_PROJECT=	fonttools
DISTNAME=	3.15.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=fonttools/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=fonttools/fonttools/}
COMMENT=	A library to manipulate font files from Python
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/fonttools-3.15.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
