# $NetBSD: Makefile,v 1.12 2012/10/05 13:52:03 asau Exp $

DISTNAME=		procps-3.0.5
CATEGORIES=		sysutils
# this sourceforge project doesn't appear to be at normal sf.net sites
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=procps/}
MASTER_SITES=		http://procps.sourceforge.net/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://procps.sourceforge.net/
COMMENT=		The Linux /proc file system utilities

# This uses Linux include/asm/page.h
ONLY_FOR_PLATFORM=	Linux-*-*

CONFLICTS+=		top-[0-9]*


USE_TOOLS+=		gmake
MAKE_ENV+=		DESTDIR=${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
