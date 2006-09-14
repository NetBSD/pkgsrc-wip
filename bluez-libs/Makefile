# $NetBSD: Makefile,v 1.13 2006/09/14 14:10:08 poppnk Exp $
#

DISTNAME=		bluez-libs-3.5
CATEGORIES=		net
MASTER_SITES=		http://bluez.sf.net/download/

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
