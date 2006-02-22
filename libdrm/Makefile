# $NetBSD: Makefile,v 1.3 2006/02/22 01:48:08 jeremy-c-reed Exp $
#

DISTNAME=		libdrm-2.0
CATEGORIES=		x11 ## fix this
MASTER_SITES=		http://dri.freedesktop.org/libdrm/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
