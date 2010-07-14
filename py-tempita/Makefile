# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:21:59 jihbed Exp $
#

DISTNAME=	Tempita-0.4.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/.tar//}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/T/Tempita/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pythonpaste.org/tempita/
COMMENT=	Tempita is a small templating language for text substitution
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Tempita-0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
