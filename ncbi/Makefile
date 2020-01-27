# $NetBSD: Makefile,v 1.8 2012/10/14 20:13:26 asau Exp $

PKGNAME=		ncbi-20120620
DISTNAME=		ncbi
DIST_SUBDIR=		ncbi-${PKGVERSION_NOREV}
CATEGORIES=		biology
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@nmsu.edu
HOMEPAGE=		https://www.ncbi.nlm.nih.gov/IEB/ToolBox/
COMMENT=		Portable, modular software for molecular biology

META_PACKAGE=		yes

DEPENDS+=	ncbi-bin-${PKGVERSION_NOREV}:../../wip/ncbi-bin
DEPENDS+=	ncbi-lib-${PKGVERSION_NOREV}:../../wip/ncbi-lib

.include "../../mk/bsd.pkg.mk"
