# $NetBSD: Makefile,v 1.15 2007/09/30 20:30:12 ondratu Exp $
#

DISTNAME=		bluez-libs-3.19
CATEGORIES=		net
MASTER_SITES=		http://bluez.sourceforge.net/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Linux Bluetooth Stack libraries

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/bluez.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=Linux-*-*

.include "../../mk/bsd.pkg.mk"
