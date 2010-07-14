# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:21:37 jihbed Exp $
#

DISTNAME=	TurboJson-1.2.1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/J/j/S/.tar//}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/T/TurboJson/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/TurboJson
COMMENT=	Python template plugin for TurboGears that supports json
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-prioritized-methods>=0.2.1:../../wip/py-prioritized-methods
DEPENDS+=	${PYPKGPREFIX}-peak-rules-[0-9]*:../../wip/py-peak-rules

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/TurboJson-1.2.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
