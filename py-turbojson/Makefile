# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	TurboJson-1.2.1
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/J/j/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=T/TurboJson/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/TurboJson
COMMENT=	Python template plugin for TurboGears that supports json
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-prioritized-methods>=0.2.1:../../wip/py-prioritized-methods
DEPENDS+=	${PYPKGPREFIX}-peak-rules-[0-9]*:../../wip/py-peak-rules

WRKSRC=		${WRKDIR}/TurboJson-1.2.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
