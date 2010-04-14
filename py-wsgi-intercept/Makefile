# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 20:27:59 jihbed Exp $
#

DISTNAME=	wsgi_intercept-0.4.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-wsgi-intercept-0.4
CATEGORIES=	 www python
MASTER_SITES=	http://pypi.python.org/packages/source/w/wsgi_intercept/
EXTRACT_SUFX=	.gz#md5=898dbfc636fef5904aa3ea8bb0722b4b

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/wsgi-intercept/
COMMENT=	Installs a WSGI application in place of a real URI for testing
#LICENSE=	mit-license

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../wip/py-httplib2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wsgi_intercept-0.4
USE_LANGUAGES=	# none

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} runtests.py )

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
