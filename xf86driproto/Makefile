# $NetBSD: Makefile,v 1.2 2006/04/28 06:29:36 jeremy-c-reed Exp $
#

DISTNAME=		xf86driproto-2.0.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86DRI extension headers from modular X.org

#CONFLICTS+=		fixesext-[0-9]*
#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xf86driproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
