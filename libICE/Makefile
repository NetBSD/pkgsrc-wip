# $NetBSD: Makefile,v 1.5 2004/02/10 18:16:17 jeremy-c-reed Exp $
#

DISTNAME=		libICE-6.3.1
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/software/xlibs
COMMENT=		Inter Client Exchange (ICE) library for X

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/ice.pc.in

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xtrans/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
