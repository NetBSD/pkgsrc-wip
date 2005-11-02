# $NetBSD: Makefile,v 1.6 2005/11/02 18:00:13 thomasklausner Exp $
#

DISTNAME=		gdal-1.2.6
PKGNAME=		gdal-docs-1.2.6
CATEGORIES=		geography
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

SUBST_CLASSES=		pyversion
SUBST_STAGE.pyversion=	do-configure
SUBST_FILES.pyversion=	GNUmakefile
SUBST_SED.pyversion=	"s:python:${PYTHONBIN}:g"
SUBST_MESSAGE.pyversion="Fixing Python Version"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
