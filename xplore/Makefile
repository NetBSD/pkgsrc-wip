# $NetBSD: Makefile,v 1.7 2012/10/07 20:11:10 asau Exp $
#

DISTNAME=		xplore-1.2a
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.musikwissenschaft.uni-mainz.de/~ag/xplore/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musikwissenschaft.uni-mainz.de/~ag/xplore/
COMMENT=		X11/Motif File Manager

PKG_DESTDIR_SUPPORT=	none

USE_IMAKE=		YES

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
