# $NetBSD: Makefile,v 1.4 2015/01/02 23:29:11 jihbed Exp $

DISTNAME=	qutip-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://qutip.org/downloads/3.1.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/qutip/
COMMENT=	Quantum Toolbox in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
