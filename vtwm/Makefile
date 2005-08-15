# $NetBSD: Makefile,v 1.1.1.1 2005/08/15 19:58:02 mnsanghvi Exp $
#

DISTNAME=		vtwm-5.4.7
PKGNAME=       vtwm
CATEGORIES=		x11 wm
MASTER_SITES=  http://www.vtwm.org/downloads/

MAINTAINER=		mehul.sanghvi@gmail.com
HOMEPAGE=		http://www.vtwm.org/downloads/
COMMENT=       TWM with virtual desktop, m4, sound and 3-D buttons.

WRKSRC=        ${WRKDIR}/${DISTNAME}
USE_IMAKE=		YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../audio/rplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
