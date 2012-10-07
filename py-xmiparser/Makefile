# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:33 asau Exp $
#

DISTNAME=	xmiparser-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	http://pypi.python.org/packages/source/x/xmiparser/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/xmiparser/
COMMENT=	XMI Parser (API for the UML XML representation specified by OMG)
LICENSE=	gnu-gpl-v2

DEPENDS+=	zope3-[0-9]*:../../www/zope3 

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
