# $NetBSD: Makefile,v 1.2 2003/07/21 17:33:13 marttikuparinen Exp $
#

DISTNAME=	ht-0.7.1
CATEGORIES=	editors
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=hte/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://hte.sourceforge.net
COMMENT=	File editor/viewer/analyzer for executables

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_NCURSES=	YES

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
