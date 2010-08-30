# $NetBSD: Makefile,v 1.2 2010/08/30 12:23:29 jihbed Exp $
#

DISTNAME=	Tempita-0.4
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/T/Tempita/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pythonpaste.org/tempita/
COMMENT=	Tempita is a small templating language for text substitution
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Tempita-0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
