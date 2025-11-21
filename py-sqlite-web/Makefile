# $NetBSD$

DISTNAME=	sqlite-web-0.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlite-web/}

MAINTAINER=	abu.maryam@msafa.org
HOMEPAGE=	https://github.com/coleifer/sqlite-web
COMMENT=	Web-based SQLite database browser
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-flask:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.0.0:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-pygments:../../textproc/py-pygments

pre-configure:
	${RM} -rf ${WRKSRC}/*/__pycache__

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
