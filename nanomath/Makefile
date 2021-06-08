# $NetBSD$

GITHUB_PROJECT=	nanomath
GITHUB_TAG=	79b7f85
DISTNAME=	nanomath-1.2.1.20210604
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/nanomath
COMMENT=	Math functions for other Oxford Nanopore processing scripts
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pandas>=1.2.4:../../math/py-pandas

WRKSRC=		${WRKDIR}/nanomath-79b7f85d004763a07c56b9eb594713ae7349ff93
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	rm ${DESTDIR}${PREFIX}/LICENSE

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
