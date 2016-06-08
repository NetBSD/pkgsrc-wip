# $NetBSD: Makefile,v 1.4 2012/10/07 12:25:30 asau Exp $
#

DISTNAME=	nose_scenario-0.1.3.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose_scenario/}
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/nose_scenario/
COMMENT=	Nose plugin test unittest scenario adapt
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose

WRKSRC=		${WRKDIR}/nose_scenario-0.1.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
