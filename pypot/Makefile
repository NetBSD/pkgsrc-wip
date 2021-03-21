# $NetBSD: Makefile,v 1.1 2014/03/14 17:41:49 jihbed Exp $

DISTNAME=	pypot-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypot/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/poppy-project/pypot
COMMENT=	Python Library for Robot Control
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
