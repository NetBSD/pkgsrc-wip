# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	mvpoly-0.93.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mvpoly/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://soliton.vm.bytemark.co.uk/pub/jjg/en/code/mvpoly.html
COMMENT=	Library for multivariate polynomials
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
