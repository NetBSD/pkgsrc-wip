# $NetBSD: Makefile,v 1.6 2007/09/05 07:48:30 bsadewitz Exp $
#

DISTNAME=		libdrm-2.3.1
CATEGORIES=		x11 graphics
MASTER_SITES=		http://bahar.aydogan.net/~blair/
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
