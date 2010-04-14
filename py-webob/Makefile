# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 09:51:39 jihbed Exp $
#

DISTNAME=	WebOb-0.9.8.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-webob-0.9.8
CATEGORIES=	 www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebOb/
EXTRACT_SUFX=	.gz#md5=07d1a1a4b0bf0faa67cb6638c632ea61

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/W/WebOb/
COMMENT=	Python module providing WSGI request and response objects
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson

WRKSRC=	${WRKDIR}/WebOb-0.9.8
PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
