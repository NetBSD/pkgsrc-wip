# $NetBSD: Makefile,v 1.5 2005/03/01 02:21:02 sifu Exp $
#

DISTNAME=		ipython-0.6.11
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://ipython.scipy.org/dist/

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://ipython.scipy.org/
COMMENT=		Interactive, enhanced Python shell

CONFLICTS=              py*-IPython-*

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
