# $NetBSD: Makefile,v 1.1 2012/11/09 17:59:19 jihbed Exp $
#

DISTNAME=	QuTiP-2.1.0
PKGNAME=	${PYPKGPREFIX}-qutip-2.1.0
CATEGORIES=	math python
MASTER_SITES=	http://qutip.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/qutip/
COMMENT=	Quantum Toolbox in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"

#options GUI, please see: http://qutip.googlecode.com/svn/doc/2.1.0/html/installation.html
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
