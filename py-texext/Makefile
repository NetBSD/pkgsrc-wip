# $NetBSD$

DISTNAME=	texext-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc math
MASTER_SITES=	https://files.pythonhosted.org/packages/11/76/ea529fb6409fd4dde7054e77e40d681900a486d8b3d83ea3a35878885975/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/matthew-brett/texext
COMMENT=	Sphinx extensions for working with LaTeX math
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.4.4:../../textproc/py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
