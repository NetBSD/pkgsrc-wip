# $NetBSD: Makefile,v 1.6 2012/11/12 16:26:47 othyro Exp $
#

DISTNAME=	MDP-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/MDP/mdp/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mdp-toolkit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://mdp-toolkit.sourceforge.net/index.html
COMMENT=	Modular toolkit for data processing
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

## <Optional Libraries>
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
#DEPENDS+=	${PYPKGPREFIX}-pp>=1.6.0:../../wip/py-pp
#DEPENDS+=	${PYPKGPREFIX}-symeig>=1.5:../../wip/py-symeig
# http://www.csie.ntu.edu.tw/~cjlin/libsvm/
# wip/py-scikits_learn
##  <Optional Libraries/>

do-test:
	${RUN} cd ${WRKSRC}/mdp; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
