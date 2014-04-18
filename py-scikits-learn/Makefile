# $NetBSD: Makefile,v 1.1 2014/04/18 21:08:10 jihbed Exp $

DISTNAME=	scikit-learn-0.14.1
EGG_NAME=	scikit_learn-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/scikit-learn/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikit-learn.org/
COMMENT=	Machine learning algorithms for python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/scikit-learn-0.14.1

USE_LANGUAGES=	c c++ fortran


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
