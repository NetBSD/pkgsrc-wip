# $NetBSD: Makefile,v 1.9 2008/08/20 15:20:40 tonnerre Exp $
#

DISTNAME=		ipython-0.8.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://ipython.scipy.org/dist/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://ipython.scipy.org/
COMMENT=		Interactive, enhanced Python shell

CONFLICTS=		py*-IPython-*

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
