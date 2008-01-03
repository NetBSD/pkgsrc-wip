# $NetBSD: Makefile,v 1.1.1.1 2008/01/03 01:40:54 hoka_adam Exp $
#

DISTNAME=	libsidplay-2.1.1+20060528.ccr
PKGNAME=	libsidplay-20060528
CATEGORIES=	audio
MASTER_SITES=	http://tnsp.org/xs-files/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://tnsp.org/xs-files/
COMMENT=	SID-chip emulator snapshot from ccr/TNSP

CONFLICTS=	libsidplay2-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	unix/libsidplay2.pc.in

.include "../../mk/bsd.pkg.mk"
