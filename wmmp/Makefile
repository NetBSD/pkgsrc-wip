# $NetBSD: Makefile,v 1.1.1.1 2004/03/24 00:56:18 rockpiper Exp $
#

DISTNAME=		WMmp-0.10.0
CATEGORIES=		audio
MASTER_SITES=		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://www.musicpd.org/
COMMENT=		Dockable MusicPD client for Window Maker and similar window managers

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_BUILDLINK3=		YES

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
