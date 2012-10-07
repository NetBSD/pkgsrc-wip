# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	Tranquil-0.2dev
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/dev//}
CATEGORIES=	databases python
MASTER_SITES=	http://tranquil.googlecode.com/files/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/tranquil/
COMMENT=	Integrating SQLAlchemy with Django

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=${SQLALCHEMYVERS}:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-django>=${DJANGOVERS}:../../www/py-django

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
