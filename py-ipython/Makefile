# $NetBSD: Makefile,v 1.2 2003/12/25 11:15:54 mpasternak Exp $
#

DISTNAME=		IPython-0.5.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://ipython.scipy.org/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ipython.scipy.org/dist/
COMMENT=		Interactive, enhanced Python shell

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
