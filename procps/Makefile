# $NetBSD: Makefile,v 1.1.1.1 2003/05/16 03:20:43 jeremy-c-reed Exp $

DISTNAME=		procps-3.0.5
CATEGORIES=		sysutils
# this sourceforge project doesn't appear to be at normal sf.net sites
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=procps/}
MASTER_SITES=		http://procps.sourceforge.net/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://procps.sourceforge.net/
COMMENT=		The Linux /proc file system utilities

# This uses Linux include/asm/page.h
ONLY_FOR_PLATFORM=	Linux-*-*

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
MAKE_ENV+=		DESTDIR=${PREFIX}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
