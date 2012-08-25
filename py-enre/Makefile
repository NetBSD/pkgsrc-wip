# $NetBSD: Makefile,v 1.1.1.1 2012/08/25 16:04:40 jihbed Exp $
#

DISTNAME=	enre-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/e/enre/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/enre
COMMENT=	This library is a Qooxdoo based GUI for Django
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/enre-0.3.4

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
