# $NetBSD$

DISTNAME=		pymssql-2.1.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pymssql/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://pymssql.org/
COMMENT=		Python interface to MS SQL
LICENSE=		gnu-lgpl-v2.1

BUILDLINK_API_DEPENDS.freetds+=	freetds>=0.91

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
