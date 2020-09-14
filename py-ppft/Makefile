# $NetBSD$

DISTNAME=	ppft-1.6.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	https://files.pythonhosted.org/packages/2b/fb/fa21f6e9aedc4823448473ed96e8eab64af1cb248c18165f045a90e1c6b4/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/ppft
COMMENT=	distributed and parallel python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
