# $NetBSD: Makefile,v 1.1.1.1 2003/11/20 04:10:08 mpasternak Exp $
#

DISTNAME=		ZODB3-3.2c1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://zope.org/Products/ZODB3.2/3.2c1/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://zope.org/Products/ZODB3.2/3.2c1/
COMMENT=		Standalone distro of Zope Object Database

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
