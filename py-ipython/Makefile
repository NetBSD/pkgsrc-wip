# $NetBSD: Makefile,v 1.3 2004/03/06 21:08:09 marc Exp $
#

DISTNAME=		IPython-0.5.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://ipython.scipy.org/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ipython.scipy.org/dist/
COMMENT=		Interactive, enhanced Python shell

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
