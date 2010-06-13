# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:20 thomasklausner Exp $
#

DISTNAME=	tv-0.5
PKGNAME=	treeviewx-0.5
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/index.html
COMMENT=	Phylogenetic tree viewer for Linux and Unix

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../x11/wxGTK26-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
