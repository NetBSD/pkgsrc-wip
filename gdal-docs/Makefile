# $NetBSD: Makefile,v 1.3 2005/03/30 23:08:46 daprice Exp $
#

DISTNAME=		gdal-1.2.5
PKGNAME=		gdal-docs-1.2.5
CATEGORIES=		wip
MASTER_SITES=		http://gdal.org/dl/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Documentation for GDAL

DEPENDS+=		doxygen>=1.4.1:../../devel/doxygen/

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

MAKEFILE=		GNUmakefile

BUILD_TARGET=		docs
INSTALL_TARGET=		install-docs

.include "../../mk/bsd.pkg.mk"
