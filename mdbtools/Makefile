# $NetBSD: Makefile,v 1.3 2005/10/24 08:58:24 rillig Exp $
#

DISTNAME=		mdbtools-0.6pre1
CATEGORIES=		wip databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mdbtools/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://mdbtools.sourceforge.net/
COMMENT=		Microsoft Access Database management tools

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
