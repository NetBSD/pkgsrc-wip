# $NetBSD: Makefile,v 1.4 2005/08/07 11:39:54 thomasklausner Exp $
#

DISTNAME=	tv-0.5
PKGNAME=	treeviewx-0.5
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/index.html
COMMENT=	Phylogenetic tree viewer for Linux and Unix

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../x11/wxGTK-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
