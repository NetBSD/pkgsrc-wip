# $NetBSD: Makefile,v 1.2 2012/04/13 22:38:16 ryo-on Exp $

SVN_REVISION=	1326
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}pre${SVN_REVISION}
PKGREVISION=	# empty
CATEGORIES=	devel
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gyp/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

SVN_REPOSITORIES=	gyp
SVN_ROOT.gyp=		http://gyp.googlecode.com/svn/trunk/
SVN_TAG.gyp=		${SVN_REVISION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/gyp

# for test
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
do-test:
	${RUN}cd ${WRKSRC}; ${SETENV} ${TEST_ENV} LINK=c++ ${PYTHONBIN} gyptest.py -a --path ${WRKSRC}/test/lib -f make

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
