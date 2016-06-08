# $NetBSD: Makefile,v 1.1 2015/06/21 23:31:33 jihbed Exp $

DISTNAME=	ipython-sql-0.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython-sql/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/ipython-sql/
COMMENT=	RDBMS access via IPython
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.6:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.9:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.1.14:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-prettytable>=0.7.2:../../textproc/py-prettytable


WRKSRC=		${WRKDIR}/ipython-sql-0.3.6

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
