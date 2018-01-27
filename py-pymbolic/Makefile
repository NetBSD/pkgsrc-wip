# $NetBSD: Makefile,v 1.2 2014/03/21 18:27:27 thomasklausner Exp $

DISTNAME=	pymbolic-2013.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymbolic/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mathema.tician.de/software/pymbolic
COMMENT=	Python package for symbolic computation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.3.5:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-pytools>=2013.5.6:../../wip/py-pytools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
