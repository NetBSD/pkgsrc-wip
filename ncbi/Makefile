# $NetBSD: Makefile,v 1.2 2005/03/08 11:44:27 thomasklausner Exp $

DISTNAME=		ncbi
PKGNAME=		ncbi-20040505
CATEGORIES=		biology
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox
COMMENT=		Portable, modular software for molecular biology

DEPENDS+=       	ncbi-bin-20040505:../../wip/ncbi-bin

NO_BUILD=		yes

do-install:
	@#empty

.include "../../wip/ncbi-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
