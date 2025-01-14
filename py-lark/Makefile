# $NetBSD$

GITHUB_PROJECT=	lark
GITHUB_TAG=	refs/tags/1.2.2
DISTNAME=	1.2.2
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_GITHUB:=lark-parser/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lark-parser/lark/
COMMENT=	Parsing toolkit for Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/lark-1.2.2
USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
