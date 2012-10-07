# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	qitensor-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science
MASTER_SITES=	http://www.stahlke.org/dan/qitensor/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.stahlke.org/dan/qitensor/
COMMENT=	Quantum Hilbert Space Tensors in Python and Sage
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	${PYTHONBIN} -c "import qitensor; test_qitensor ()"

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
