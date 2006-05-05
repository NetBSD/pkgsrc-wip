# $NetBSD: Makefile,v 1.4 2006/05/05 22:26:58 jeremy-c-reed Exp $
#

DISTNAME=		libdrm-2.0
CATEGORIES=		devel
MASTER_SITES=		http://dri.freedesktop.org/libdrm/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
