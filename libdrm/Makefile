# $NetBSD: Makefile,v 1.7 2007/12/08 08:01:51 bsadewitz Exp $
#

DISTNAME=		libdrm-2.3.1
PKGREVISION=		1
CATEGORIES=		x11 graphics
MASTER_SITES=		http://www.netbsd.org/~bjs/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bjs@NetBSD.org
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
