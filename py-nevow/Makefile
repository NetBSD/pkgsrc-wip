# $NetBSD: Makefile,v 1.1.1.1 2004/05/25 17:51:54 mpasternak Exp $
#

DISTNAME=		Nevow-0.2.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/N/n/}
CATEGORIES=		www
MASTER_SITES=		http://www.divmod.org/users/release/divmod/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Home/Projects/Nevow/index.html
COMMENT=		Next-generation web application templating system

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.2.0:../../wip/py-twisted

WRKSRC=			${WRKDIR}/${DISTNAME:S/N/n/}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
