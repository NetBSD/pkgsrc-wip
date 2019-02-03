# $NetBSD$

DISTNAME=	attrdict-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://files.pythonhosted.org/packages/35/bb/bac3e42ae04bc082c28cd8186bfb5b50fb240a4f7419f876c683125ccc8b/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bcj/AttrDict
COMMENT=	Dict with attribute-style access
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
