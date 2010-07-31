# $NetBSD: Makefile,v 1.5 2010/07/31 01:00:21 jihbed Exp $
#

DISTNAME=	coverage-3.3.1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/coverage/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nedbatchelder.com/code/coverage/
COMMENT=	Python module that measures and testing code coverage for Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/coverage-3.3.1
USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
