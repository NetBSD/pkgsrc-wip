# $NetBSD$

DISTNAME=	nxpd-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/6a/fe/2ec17a6fbbff333db22a6ee84dbb2ba09ecb3ff111d37e7ff3aec69852a1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/chebee7i/nxpd
COMMENT=	NetworkX Pydot Draw
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.7:../../devel/py-pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
