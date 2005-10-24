# $NetBSD: Makefile,v 1.1.1.1 2005/10/24 00:27:17 poppnk Exp $
#

DISTNAME=		mdbtools-0.6pre1
CATEGORIES=		wip databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mdbtools/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://voxel.dl.sourceforge.net/sourceforge/mdbtools/
COMMENT=		Microsoft Access Database management tools

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
