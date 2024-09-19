# $NetBSD$

DISTNAME=	Flask-Migrate-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Migrate/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/miguelgrinberg/flask-migrate
COMMENT=	SQLAlchemy database migrations for Flask applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask>=0.10:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-sqlalchemy>=1.0:../../www/py-flask-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-alembic>=0.6:../../databases/py-alembic

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
