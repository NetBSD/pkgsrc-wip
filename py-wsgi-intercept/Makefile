# $NetBSD: Makefile,v 1.3 2012/10/14 22:09:06 thomasklausner Exp $
#

DISTNAME=	wsgi_intercept-0.4
PKGNAME=	${PYPKGPREFIX}-wsgi-intercept-0.4
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsgi_intercept/}
EXTRACT_SUFX=	.tar.gz#md5=898dbfc636fef5904aa3ea8bb0722b4b

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/wsgi-intercept/
COMMENT=	Installs a WSGI application in place of a real URI for testing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../www/py-httplib2

USE_LANGUAGES=	# none

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} runtests.py )

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
