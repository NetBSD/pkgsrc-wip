# $NetBSD: Makefile,v 1.1.1.1 2005/11/13 08:07:11 bartoszkuzma Exp $
#

DISTNAME=		pymssql-0.7.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pymssql/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://pymssql.sourceforge.net/
COMMENT=		Python interface to MS SQL

BUILDLINK_DEPENDS.freetds+=	freetds>=0.63

PYTHON_VERSION_REQD=	24
PY_PATCHPLIST=		yes
PYBINMODULE=		yes
PYDISTUTILSPKG=		yes

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
