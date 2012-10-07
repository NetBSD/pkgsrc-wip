# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	ToscaWidgets-0.9.9
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/W/w/}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/T/ToscaWidgets/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://toscawidgets.org/
COMMENT=	Web widget creation toolkit based on TurboGears widgets
LICENSE=  	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

WRKSRC=		${WRKDIR}/ToscaWidgets-0.9.9
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
