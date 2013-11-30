# $NetBSD: Makefile,v 1.1 2013/11/30 15:50:12 jihbed Exp $

DISTNAME=	easydev-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/e/easydev/
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://packages.python.org/easydev/
COMMENT=	Common utilities to ease the development of Python packages
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.3:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
