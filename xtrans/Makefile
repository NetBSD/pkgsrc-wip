# $NetBSD: Makefile,v 1.3 2003/11/27 00:00:58 xtraeme Exp $
#

DISTNAME=		libXtrans-0.1
PKGNAME=		xtrans-0.1
CATEGORIES=		new
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://freedesktop.org/~xlibs/dist/
COMMENT=		Network API translation layer to insulate X

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xtrans.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
