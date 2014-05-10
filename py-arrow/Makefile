# $NetBSD: Makefile,v 1.1 2014/05/10 21:40:30 jihbed Exp $

DISTNAME=	arrow-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	https://pypi.python.org/packages/source/a/arrow/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://crsmithdev.com/arrow/
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 34 33 27 26

.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
.include "../../mk/bsd.pkg.mk"
