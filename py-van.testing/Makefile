# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 20:28:38 jihbed Exp $
#

DISTNAME=	van.testing-3.0.0.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	   www python
MASTER_SITES=	http://pypi.python.org/packages/source/v/van.testing/
EXTRACT_SUFX=	.gz#md5=aab7ad2abd49b09fc44c9f3ca8acbbb0

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/van.testing
COMMENT=	Layers for zope.testing to simplify test setups
LICENSE=		zpl

DEPENDS+=	${PYPKGPREFIX}-wsgi-intercept>=0.4:../../wip/py-wsgi-intercept
#DEPENDS+=	zope3>=0.3.3:../../www/zope3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/van.testing-3.0.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
