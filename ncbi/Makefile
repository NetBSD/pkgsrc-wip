# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 20:35:43 daprice Exp $

DISTNAME=		ncbi
PKGNAME=		ncbi-20030611
CATEGORIES=		biology
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.ncbi.nlm.nih.gov/IEB/ToolBox
COMMENT=		Portable, modular software for molecular biology

DEPENDS+=       	ncbi-bin-20030611:../../wip/ncbi-bin

NO_BUILD=		yes

do-install:
	@#empty

.include "../../wip/ncbi-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
