# $NetBSD: Makefile,v 1.8 2013/01/13 13:10:03 ryo-on Exp $

SVN_REVISION=	1559
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}pre${SVN_REVISION}
CATEGORIES=	devel
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gyp/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

SVN_REPOSITORIES=	gyp
SVN_ROOT.gyp=		http://gyp.googlecode.com/svn/trunk/
SVN_TAG.gyp=		${SVN_REVISION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/gyp

# for test
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
do-test:
	${RUN}cd ${WRKSRC}; LANG=C ${SETENV} ${TEST_ENV} ${PYTHONBIN} gyptest.py -a -f make --passed

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
