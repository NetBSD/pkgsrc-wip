# $NetBSD$

DISTNAME=	docplex-2.15.194
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/9b/76/ebf5b75a25c4357c9a4758cae7fea778dd7f282b83c2f22e150dc7e3c852/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://onboarding-oaas.docloud.ibmcloud.com/software/analytics/docloud/
COMMENT=	The IBM Decision Optimization CPLEX Modeling for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
