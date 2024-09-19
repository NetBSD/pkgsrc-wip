# $NetBSD$

DISTNAME=	pycm-2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/ad/95/4e73b9750c77eca7ff43e32f6ba792722bd99eb63cf1a0fe8b4c58775b4d/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sepandhaghighi/pycm
COMMENT=	Multi-class confusion matrix library in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-art>=4.8:../../wip/py-art

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.9.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
