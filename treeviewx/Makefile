# $NetBSD: Makefile,v 1.9 2012/10/07 17:17:48 asau Exp $
#

DISTNAME=	treeviewx_0.5.1+20100823.orig
PKGNAME=	treeviewx-0.5.1.20100823
CATEGORIES=	biology
#MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/treeviewx/}


MAINTAINER=	hdp@cs.nmsu.edu
#HOMEPAGE=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/index.html
HOMEPAGE=	https://packages.debian.org/unstable/science/treeviewx
COMMENT=	Phylogenetic tree viewer for Linux and Unix

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/tv-0.5

.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
