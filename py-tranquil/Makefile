# $NetBSD: Makefile,v 1.1.1.1 2009/04/24 22:03:05 jihbed Exp $
#

DISTNAME=	Tranquil-0.2dev
PKGNAME=	${PYPKGPREFIX}-tranquil-0.2
CATEGORIES=	databases
MASTER_SITES=	http://tranquil.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/tranquil/
COMMENT=	Integrating SQLAlchemy with Django

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=${SQLALCHEMYVERS}:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-django>=${DJANGOVERS}:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
