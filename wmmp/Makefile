# $NetBSD: Makefile,v 1.5 2005/06/12 23:51:30 kristerw Exp $
#

DISTNAME=		WMmp-0.10.0
CATEGORIES=		audio
MASTER_SITES=		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://www.musicpd.org/
COMMENT=		Dockable MusicPD client for Window Maker and similar window managers

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
