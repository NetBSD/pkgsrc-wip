# $NetBSD: Makefile,v 1.2 2004/08/12 20:23:06 rockpiper Exp $
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
USE_X11=		YES
USE_BUILDLINK3=		YES

pre-configure:
	cd ${WRKSRC};                                           \
	${AUTOCONF}

.include "../../mk/autoconf.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
