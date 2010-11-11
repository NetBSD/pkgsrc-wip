# $NetBSD: Makefile,v 1.2 2010/11/11 22:42:07 shattered Exp $
#

DISTNAME=	Pylons-1.0.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/S/.tar//}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pylons/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylonshq.com/
COMMENT=	Pylons Web Framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-cheetah>=2.0.1:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.7.2:../../www/py-paste

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/Pylons-1.0
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/conftest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
