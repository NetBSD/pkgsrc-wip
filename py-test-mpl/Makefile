# $NetBSD$

DISTNAME=	pytest-mpl-0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ae/e9/82536e05e60d27786d0256982279882765aebaa017812b42cc21cc33591c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/matplotlib/pytest-mpl
COMMENT=	Pytest plugin to help with testing figures output from Matplotlib
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.2.2:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
