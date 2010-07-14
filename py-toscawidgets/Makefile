# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:20:46 jihbed Exp $
#

DISTNAME=	ToscaWidgets-0.9.9.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/W/w/S/.tar//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/T/ToscaWidgets/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://toscawidgets.org/
COMMENT=	Web widget creation toolkit based on TurboGears widgets
LICENSE=  	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 25 24

WRKSRC=		${WRKDIR}/ToscaWidgets-0.9.9
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
