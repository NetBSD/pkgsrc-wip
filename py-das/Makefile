# $NetBSD: Makefile,v 1.1 2014/06/07 17:04:23 jihbed Exp $

DISTNAME=	pydas-0.2.32
PKGNAME=	${PYPKGPREFIX}-das-0.2.32
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydas/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/midasplatform/pydas
COMMENT=	Upload data to a Midas-based application with Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
