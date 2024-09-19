# $NetBSD: Makefile,v 1.7 2012/10/07 12:25:36 asau Exp $
#

DISTNAME=	openxmllib-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://openxmllib.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/openxmllib/
COMMENT=	Provides resources to handle OpenXML documents from Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
