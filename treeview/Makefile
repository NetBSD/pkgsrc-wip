# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 20:52:15 daprice Exp $
#

DISTNAME=	tv-0.3
PKGNAME=        treeviewx-0.3
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=       http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/index.html
COMMENT=	Phylogenetic tree viewer for Linux and Unix

USE_GNU_TOOLS+= make
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
