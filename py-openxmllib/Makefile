# $NetBSD: Makefile,v 1.1.1.1 2009/05/02 00:06:32 jihbed Exp $
#

DISTNAME=	openxmllib-1.0.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://openxmllib.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/openxmllib/
COMMENT=	Provides resources to handle OpenXML documents from Python

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	26 25 24


.include "../../lang/python/egg.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
