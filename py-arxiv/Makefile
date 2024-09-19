# $NetBSD$

DISTNAME=	arxiv-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	https://files.pythonhosted.org/packages/7b/c4/f1c53cdff1e8fbd3eba97276a5112745c1cb861bad43fb5b7c5c033159c1/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/lukasschwab/arxiv.py
COMMENT=	Python wrapper for the arXiv API
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-feedparser>=5.2.1<6.0.0:../../textproc/py-feedparser5
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
TEST_DEPENDS+=	# TODO: pytest>=0

USE_LANGUAGES=	# none

#BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.19.1
#.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
