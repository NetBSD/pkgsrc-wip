# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:31 asau Exp $
#

DISTNAME=	enre-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enre/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/enre
COMMENT=	This library is a Qooxdoo based GUI for Django
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

WRKSRC=			${WRKDIR}/enre-0.3.4

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
