# $NetBSD$

DISTNAME=	pylama-7.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	https://files.pythonhosted.org/packages/a7/f1/c668760a25e9382e71009e7c98b687ec32068462bdfa8179764cd14c1071/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-flakes>=2.1.1:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6.1:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-docstyle>=3.0.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.5.0:../../wip/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
