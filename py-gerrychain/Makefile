# $NetBSD$

DISTNAME=	gerrychain-0.2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/79/76/0ad276d1eda834f6a9e42f62488cf394548b88a25f44a1b57b386acb6b86/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/79/76/0ad276d1eda834f6a9e42f62488cf394548b88a25f44a1b57b386acb6b86/
COMMENT=	Markov chain Monte Carlo to analyze districting plans and gerrymanders
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.2.3:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
