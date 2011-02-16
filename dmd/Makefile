# $NetBSD: Makefile,v 1.1.1.1 2011/02/16 17:10:41 thomasklausner Exp $
#

DISTNAME=	dmd.2.051
PKGNAME=	${DISTNAME:S/dmd./dmd-/}
CATEGORIES=	lang
MASTER_SITES=	http://ftp.digitalmars.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digitalmars.com/d/
COMMENT=	Digital Mars D compiler
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/dmd2

BUILD_DIRS=	src/dmd src/druntime src/phobos
MAKE_FILE=	posix.mak
# -j 16 passed to g++
MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

# so we can use the same MAKE_FILE name for both BUILD_DIRS
post-extract:
	cd ${WRKSRC}/src/dmd && ln -f linux.mak posix.mak

.include "../../mk/bsd.pkg.mk"
