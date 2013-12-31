# $NetBSD: Makefile,v 1.6 2013/12/31 20:09:14 othyro Exp $
#

DISTNAME=	restkit-4.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/r/restkit/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/benoitc/restkit/
COMMENT=	Restkit is an HTTP resource kit for Python
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	restkit/contrib/webob_api.py
DOCDIR=			share/doc/${PKGBASE:S/${PYPKGPREFIX}/py/1}
INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/restkit/README.rst \
		${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} -rf ${DESTDIR}${PREFIX}/restkit

DEPENDS+=	${PYPKGPREFIX}-http-parser>=0.8.3:../../www/py-http-parser
DEPENDS+=	${PYPKGPREFIX}-socketpool>=0.5.3:../../net/py-socketpool
DEPENDS+=       ${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=       ${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=       ${PYPKGPREFIX}-eventlet>=0.9.7:../../wip/py-eventlet
DEPENDS+=       ${PYPKGPREFIX}-gevent>=0.13.0:../../wip/py-gevent
DEPENDS+=       ${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
