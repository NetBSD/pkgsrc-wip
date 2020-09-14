# $NetBSD$

DISTNAME=	pathos-0.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/be/ea/b2cf3a6561fc5deb64de8ae0af5e3e4e2db03ca588cb7415efce4a8de26e/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/pathos
COMMENT=	Parallel graph management and execution in heterogeneous computing
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.2:../../wip/py-dill
DEPENDS+=	${PYPKGPREFIX}-multiprocess>=0.70.10:../../wip/py-multiprocess
DEPENDS+=	${PYPKGPREFIX}-ppft>=1.6.6.2:../../wip/py-ppft
DEPENDS+=	${PYPKGPREFIX}-pox>=0.2.8:../../wip/py-pox

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
