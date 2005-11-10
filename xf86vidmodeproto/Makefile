# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 01:49:53 jeremy-c-reed Exp $
#

DISTNAME=		xf86vidmodeproto-2.2.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86VidMode extension headers from modular X.org

#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xf86vidmodeproto.pc.in
USE_LANGUAGES=		# empty

.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
