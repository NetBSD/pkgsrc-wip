# $NetBSD: Makefile,v 1.10 2014/08/20 13:28:30 thomasklausner Exp $

DISTNAME=	restkit-4.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/restkit/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/benoitc/restkit/
COMMENT=	Restkit is an HTTP resource kit for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-http-parser>=0.8.3:../../www/py-http-parser
DEPENDS+=	${PYPKGPREFIX}-socketpool>=0.5.3:../../net/py-socketpool
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-eventlet>=0.9.7:../../wip/py-eventlet
DEPENDS+=	${PYPKGPREFIX}-gevent>=0.13.0:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-WebOb>=0.9.8:../../www/py-WebOb

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	restkit/contrib/webob_api.py
DOCDIR=			share/doc/${PKGBASE:S/${PYPKGPREFIX}/py/1}
INSTALLATION_DIRS+=	${DOCDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-socketpool

post-install:
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/restkit/README.rst \
		${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} -rf ${DESTDIR}${PREFIX}/restkit

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
