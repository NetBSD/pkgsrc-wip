# $NetBSD: Makefile,v 1.7 2004/05/10 22:52:13 jeremy-c-reed Exp $

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

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
MAKE_ENV+=		DESTDIR=${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
