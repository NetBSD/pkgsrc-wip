# $NetBSD: Makefile,v 1.9 2012/10/07 17:17:48 asau Exp $
#

DISTNAME=	tv-0.5
PKGNAME=	treeviewx-0.5
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/index.html
COMMENT=	Phylogenetic tree viewer for Linux and Unix

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../x11/wxGTK26-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
