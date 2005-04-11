# $NetBSD: Makefile,v 1.3 2005/04/11 21:16:14 tvierling Exp $
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

pre-configure:
	cd ${WRKSRC};                                           \
	${AUTOCONF}

.include "../../mk/autoconf.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
