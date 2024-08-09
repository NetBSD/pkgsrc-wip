# $NetBSD: Makefile,v 1.1 2014/05/10 15:23:39 jihbed Exp $

DISTNAME=	shutilwhich-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shutilwhich/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mbr/shutilwhich
COMMENT=	Shutil.which for those not using Python 3.3 yet
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
