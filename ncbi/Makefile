# $NetBSD: Makefile,v 1.6 2006/07/02 19:04:35 shattered Exp $

DISTNAME=		ncbi
PKGNAME=		ncbi-20060301
CATEGORIES=		biology
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		mchittur@nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox/
COMMENT=		Portable, modular software for molecular biology

DEPENDS+=       	ncbi-bin-20060301:../../wip/ncbi-bin

NO_BUILD=		yes

do-install:
	@#empty

.include "../../wip/ncbi-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
