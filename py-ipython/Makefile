# $NetBSD: Makefile,v 1.7 2005/04/11 21:15:00 tvierling Exp $
#

DISTNAME=		ipython-0.6.12
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://ipython.scipy.org/dist/

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://ipython.scipy.org/
COMMENT=		Interactive, enhanced Python shell

CONFLICTS=              py*-IPython-*

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
