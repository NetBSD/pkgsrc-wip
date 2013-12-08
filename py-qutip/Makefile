# $NetBSD: Makefile,v 1.2 2013/12/08 19:06:33 jihbed Exp $

DISTNAME=	QuTiP-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://qutip.org/downloads/2.2.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/qutip/
COMMENT=	Quantum Toolbox in Python
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/qutip-2.2.0

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
#.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
