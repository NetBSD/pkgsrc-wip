# $NetBSD: Makefile,v 1.4 2009/08/30 21:31:00 jihbed Exp $
#

DISTNAME=	coverage-3.0.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/coverage/
EXTRACT_SUFX=	.gz#md5=9c40e153a80fc42944c11ce11ab02de5

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nedbatchelder.com/code/coverage/
COMMENT=	Python module that measures and testing code coverage for Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/coverage-3.0.1

USE_LANGUAGES=	c
BUILD_TARGET=	tracer.so

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
