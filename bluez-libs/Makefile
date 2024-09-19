# $NetBSD: Makefile,v 1.18 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		bluez-libs-3.19
CATEGORIES=		net
MASTER_SITES=		http://bluez.sourceforge.net/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Linux Bluetooth Stack libraries

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/bluez.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
