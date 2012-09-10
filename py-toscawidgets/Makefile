# $NetBSD: Makefile,v 1.4 2012/09/10 23:34:22 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ToscaWidgets-0.9.9
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
