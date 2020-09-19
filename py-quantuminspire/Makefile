# $NetBSD$

DISTNAME=	quantuminspire-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/33/54/861780f3164428a20c336385ae0941882fb20b3464bec315eae1dfa004b0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.org/project/quantuminspire/
COMMENT=	SDK for the Quantum Inspire platform
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.6.3:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-latexenc>=2.7:../../wip/py-latexenc
DEPENDS+=	${PYPKGPREFIX}-coreapi>=2.3.3:../../wip/py-coreapi
DEPENDS+=	${PYPKGPREFIX}-nbimporter>=0.3.2:../../wip/py-nbimporter

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
