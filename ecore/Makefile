# $NetBSD: Makefile,v 1.13 2007/12/04 18:27:25 netcap Exp $
#

DISTNAME=	ecore-0.9.9.041
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--disable-openssl --disable-ecore-directfb

.include "../../wip/eet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
