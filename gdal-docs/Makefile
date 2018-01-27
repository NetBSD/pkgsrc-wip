# $NetBSD: Makefile,v 1.12 2012/09/29 00:50:34 asau Exp $
#

DISTNAME=		gdal-1.3.1
PKGNAME=		gdal-docs-1.3.1
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://gdal.org/dl/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Documentation for GDAL

DEPENDS+=		doxygen>=1.4.1:../../devel/doxygen


USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

MAKE_FILE=		GNUmakefile

BUILD_TARGET=		docs
INSTALL_TARGET=		install-docs

SUBST_CLASSES+=			pyversion
SUBST_STAGE.pyversion=		do-configure
SUBST_FILES.pyversion=		GNUmakefile
SUBST_SED.pyversion=		-e 's:python:${PYTHONBIN}:g'
SUBST_MESSAGE.pyversion=	Fixing Python Version

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Fixing typo in the configure script.
SUBST_FILES.conf=	configure
SUBST_SED.conf=		-e 's,6LIBZ$$,6,'

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
