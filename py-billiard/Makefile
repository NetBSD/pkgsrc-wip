# $NetBSD: Makefile,v 1.2 2013/07/01 12:25:30 othyro Exp $
#

DISTNAME=	billiard-2.7.3.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	http://pypi.python.org/packages/source/b/billiard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

REPLACE_PYTHON+=	funtests/setup.py funtests/tests/test_multiprocessing.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
