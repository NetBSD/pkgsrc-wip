# $NetBSD$

DISTNAME=	mozlog-8.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/4a/d6/198a58f197afb9482050671c4a9b0ee299c005cf39c4113589b726e9f915/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Robust log handling specialized for logging in the Mozilla universe
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-blessed>=1.3:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-mozterm>=1.0.0:../../wip/py-mozterm
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-mozfile>=2.1.0:../../wip/py-mozfile

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
