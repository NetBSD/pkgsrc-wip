# $NetBSD: Makefile,v 1.1.1.1 2005/03/17 21:16:52 daprice Exp $
#

DISTNAME=		gdal-1.2.5
PKGNAME=		gdal-doc-1.2.5
CATEGORIES=		wip
MASTER_SITES=		http://gdal.org/dl/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Documentation for GDAL

EPENDS+=		doxygen>=1.4.1:../../devel/doxygen/

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

MAKEFILE=		GNUmakefile

BUILD_TARGET=		docs
INSTALL_TARGET=		install-docs

.include "../../mk/bsd.pkg.mk"
