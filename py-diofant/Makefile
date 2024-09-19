# $NetBSD$

DISTNAME=	Diofant-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/14/e2/f2d8b77cd854176710f51e30dcf7d9fbfd6d5ae14d127d8b19c4c89516f5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/14/e2/f2d8b77cd854176710f51e30dcf7d9fbfd6d5ae14d127d8b19c4c89516f5/
COMMENT=	Computer algebra system (CAS) in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-strategies>=0.2.3:../../wip/py-strategies

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
