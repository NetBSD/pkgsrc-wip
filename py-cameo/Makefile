# $NetBSD: Makefile,v 1.1 2015/08/05 20:32:55 jihbed Exp $

DISTNAME=	cameo-0.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cameo/}


MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	${MASTER_SITE_PYPI:=c/cameo/}
COMMENT=	Computer aided metabolic engineering & optimziation
LICENSE=	apache-2.0

#DEPENDS+=	${PYPKGPREFIX}-cobra>=0.4.0:../../wip/py-cobra-0.4.0
#DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy>=1.2.0:../../wip/py-lazy-object-proxy-1.2.0

WRKSRC=		${WRKDIR}/cameo-0.4.9

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
