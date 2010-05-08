# $NetBSD: Makefile,v 1.4 2010/05/08 18:14:08 jihbed Exp $
#

DISTNAME=	openxmllib-1.0.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://openxmllib.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/openxmllib/
COMMENT=	Provides resources to handle OpenXML documents from Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
