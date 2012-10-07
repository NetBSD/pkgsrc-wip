# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:26 asau Exp $
#

DISTNAME=	pebl-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pebl-project.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pebl-project.googlecode.com/
COMMENT=	Python Environment for Bayesian Learning
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
