# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:09 grantbeattie Exp $
#

DISTNAME=	ht-0.7.1
CATEGORIES=	editors
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=hte/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://hte.sourceforge.net
COMMENT=	File editor/viewer/analyzer for executables

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_NCURSES=	YES

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
