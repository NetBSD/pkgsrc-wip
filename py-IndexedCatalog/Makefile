# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 15:17:26 mpasternak Exp $
#

DISTNAME=		IndexedCatalog-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://async.com.br/projects/IndexedCatalog/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://async.com.br/projects/IndexedCatalog/
COMMENT=		Indexed Catalog extension for standalone ZODB

# remove when buildlink for ZODB is available
DEPENDS+=		${PYPKGPREFIX}-ZODB3>=3.2:../../databases/py-ZODB

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
# when it is ready:
# .include "../../databases/py-ZODB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
