# $NetBSD: Makefile,v 1.1 2013/12/03 00:44:55 jihbed Exp $

DISTNAME=	mvpoly-0.93.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/m/mvpoly/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://soliton.vm.bytemark.co.uk/pub/jjg/en/code/mvpoly.html
COMMENT=	Library for multivariate polynomials
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
