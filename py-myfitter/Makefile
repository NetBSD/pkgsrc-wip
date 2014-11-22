# $NetBSD: Makefile,v 1.1 2014/11/22 13:42:46 jihbed Exp $

DISTNAME=	myFitter-python-0.1.3
EGG_NAME=	myFitter_python-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//:tl}
CATEGORIES=	math python
MASTER_SITES=	http://www.hepforge.org/archive/myfitter/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://myfitter.hepforge.org/
COMMENT=	Maximum Likelihood Fits in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
