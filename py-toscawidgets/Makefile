# $NetBSD: Makefile,v 1.6 2014/08/20 13:28:30 thomasklausner Exp $

DISTNAME=	ToscaWidgets-0.9.9
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/W/w/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/ToscaWidgets/}
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://toscawidgets.org/
COMMENT=	Web widget creation toolkit based on TurboGears widgets
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-WebOb>=0.9.8:../../www/py-WebOb

WRKSRC=		${WRKDIR}/ToscaWidgets-0.9.9
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
