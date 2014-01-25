# $NetBSD: Makefile,v 1.4 2014/01/25 10:38:22 thomasklausner Exp $

DISTNAME=	Pylons-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pylons/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylonshq.com/
COMMENT=	Pylons Web Framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-cheetah>=2.0.1:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.7.2:../../www/py-paste

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-cheetah, py-paste

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/conftest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
