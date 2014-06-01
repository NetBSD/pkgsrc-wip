# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	pytools-2013.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/p/pytools/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pytools
COMMENT=	Collection of tools for Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/pytools-2013.5.6

USE_LANGUAGES=	# none

DEPENDS+=       ${PYPKGPREFIX}-decorator>=3.3.2:../../devel/py-decorator
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
