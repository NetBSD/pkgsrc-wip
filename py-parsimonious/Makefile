# $NetBSD$

DISTNAME=	parsimonious-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/02/fc/067a3f89869a41009e1a7cdfb14725f8ddd246f30f63c645e8ef8a1c56f4/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/erikrose/parsimonious
COMMENT=	The fastest pure-Python PEG parser I could muster
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
