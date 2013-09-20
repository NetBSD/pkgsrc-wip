# $NetBSD: Makefile,v 1.1 2013/09/20 09:50:35 jihbed Exp $

DISTNAME=	pytools-2013.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/p/pytools/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pytools
COMMENT=	Collection of tools for Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/pytools-2013.5.6

USE_LANGUAGES=	# none

DEPENDS+=       ${PYPKGPREFIX}-decorator>=3.3.2:../../devel/py-decorator
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
