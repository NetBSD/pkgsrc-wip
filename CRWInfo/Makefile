# $NetBSD: Makefile,v 1.1.1.1 2005/01/14 00:24:53 kirtai Exp $
#

DISTNAME=		CRWInfo-0.2
CATEGORIES=		graphics
MASTER_SITES=		http://neuemuenze.heim1.tu-clausthal.de/~sven/crwinfo/

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://neuemuenze.heim1.tu-clausthal.de/~sven/crwinfo/
COMMENT=		Extract exposure information and thumbnails from Canons RAW files

USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crwinfo ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/crwinfo/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/crwinfo/

.include "../../mk/bsd.pkg.mk"
