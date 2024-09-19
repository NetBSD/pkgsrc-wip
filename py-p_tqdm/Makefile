# $NetBSD$

DISTNAME=	p_tqdm-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	https://files.pythonhosted.org/packages/b9/c4/ce6abe2fa3868b1ea9216a81522a9ece36f47bdbb966f8f31f76e2967178/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/swansonk14/p_tqdm
COMMENT=	Parallel processing with progress bars
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.48.2:../../misc/py-tqdm
#DEPENDS+=	${PYPKGPREFIX}-pathos>=0.2.6:../../wip/py-pathos
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
