# $NetBSD: Makefile,v 1.3 2015/01/31 23:09:55 jihbed Exp $

DISTNAME=	pytools-2014.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytools/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pytools
COMMENT=	Collection of tools for Python
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-decorator>=3.3.2:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
