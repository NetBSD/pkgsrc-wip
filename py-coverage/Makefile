# $NetBSD: Makefile,v 1.3 2009/07/05 11:01:03 jihbed Exp $
#

DISTNAME=	coverage-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/ned/coveragepy/downloads/
EXTRACT_SUFX=	.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nedbatchelder.com/code/coverage/
COMMENT=	Python module that measures and testing code coverage for Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=		user-destdir

WRKSRC=		${WRKDIR}/coveragepy

USE_TOOLS+=	tar
USE_LANGUAGES=	c c++
BUILD_TARGET=	tracer.so

post-extract:
	cd ${WRKDIR} && ${TAR} -xvf ${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
