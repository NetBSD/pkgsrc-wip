# $NetBSD: Makefile,v 1.9 2006/03/23 00:08:27 mchittur Exp $
#

DISTNAME=		gdal-1.3.1
PKGNAME=		gdal-docs-1.3.1
CATEGORIES=		wip
MASTER_SITES=		http://gdal.org/dl/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Documentation for GDAL

DEPENDS+=		doxygen>=1.4.1:../../devel/doxygen

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

MAKEFILE=		GNUmakefile

BUILD_TARGET=		docs
INSTALL_TARGET=		install-docs

SUBST_CLASSES+=		pyversion
SUBST_STAGE.pyversion=	do-configure
SUBST_FILES.pyversion=	GNUmakefile
SUBST_SED.pyversion=	-e 's:python:${PYTHONBIN}:g'
SUBST_MESSAGE.pyversion=Fixing Python Version

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
