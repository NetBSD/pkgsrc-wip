# $NetBSD: Makefile,v 1.8 2008/06/02 05:55:40 bsadewitz Exp $
#

DISTNAME=		libdrm-${LIBDRM_DISTVERSION}.${LIBDRM_PATCHLEVEL}
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/bjs/distfiles/
EXTRACT_SUFX=		.tar.bz2

LIBDRM_PATCHLEVEL=	0
LIBDRM_DISTVERSION=	2.3.1

MAINTAINER=		bjs@NetBSD.org
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

ONLY_FOR_PLATFORM=	NetBSD-[4-9]*-* # XXX NetBSD specific API changes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}-${LIBDRM_DISTVERSION}

.include "../../mk/bsd.pkg.mk"
