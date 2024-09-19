# $NetBSD$

DISTNAME=	scholarmetrics-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category
MASTER_SITES=	https://files.pythonhosted.org/packages/28/7d/e5a5bf57b4a9e7b05c8b9c4432cebc88bcbf04366cffc54a3380af6ebdf8/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/28/7d/e5a5bf57b4a9e7b05c8b9c4432cebc88bcbf04366cffc54a3380af6ebdf8/
COMMENT=	Compute scholarly metrics in Python with Pandas and NumPy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pbr>=5.1.1:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.4:../../math/py-pandas

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
