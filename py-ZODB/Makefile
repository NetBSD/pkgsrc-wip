# $NetBSD: Makefile,v 1.2 2003/11/20 04:38:42 mpasternak Exp $
#

DISTNAME=		ZODB3-3.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://zope.org/Products/ZODB3.2/3.2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://zope.org/Products/ZODB3.2/3.2/
COMMENT=		Standalone distro of Zope Object Database

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
