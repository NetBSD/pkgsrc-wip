# $NetBSD: Makefile,v 1.1 2013/07/31 02:19:21 jihbed Exp $

DISTNAME=	decimalpy-0.101
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/d/decimalpy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.bruunisejs.dk/PythonHacks/
COMMENT=	Decimal based version of numpy
LICENSE=	python-software-foundation


USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
