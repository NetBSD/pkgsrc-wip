# $NetBSD: Makefile,v 1.14 2007/12/05 06:29:49 netcap Exp $
#

DISTNAME=	ecore-0.9.9.041
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=   http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+= 	--disable-openssl \
		 	--disable-ecore-directfb \
			--enable-ecore-evas-x11-16 \
			--enable-ecore-desktop

.include "../../wip/eet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
