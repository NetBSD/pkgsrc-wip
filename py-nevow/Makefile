# $NetBSD: Makefile,v 1.2 2004/05/27 13:09:25 mpasternak Exp $
#

DISTNAME=		Nevow-0.2.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/N/n/}
CATEGORIES=		www
MASTER_SITES=		http://www.divmod.org/users/release/divmod/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Home/Projects/Nevow/index.html
COMMENT=		Next-generation web application templating system

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.2.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-XML>=0.8.3:../../textproc/py-xml

WRKSRC=			${WRKDIR}/${DISTNAME:S/N/n/}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
