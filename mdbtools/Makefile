# $NetBSD: Makefile,v 1.5 2009/06/02 12:22:28 noud4 Exp $
#

DISTNAME=		mdbtools-0.6pre1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mdbtools/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://mdbtools.sourceforge.net/
COMMENT=		Microsoft Access Database management tools

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=		3.4
.if !empty(MACHINE_PLATFORM:MNetBSD-4*) || !empty(MACHINE_PLATFORM:MNetBSD-5*)
USE_PKGSRC_GCC=		yes
.endif
.include "../../mk/compiler.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
