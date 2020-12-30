# $NetBSD$

DISTNAME=	hugo-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/68/28/bcdaf2fab2ee08f7f1d116ae42b28d80541a12e07eee04c4782985dde820/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Roolat/hugo
COMMENT=	Discord bot library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-discord.py>=0:../../wip/py-discord.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
