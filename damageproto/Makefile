# $NetBSD: Makefile,v 1.2 2006/03/12 03:35:36 jeremy-c-reed Exp $
#

DISTNAME=		damageproto-1.0.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Damage extension headers from modular X.org

#CONFLICTS+=		xorg-libs-[0-9]* # not in same PREFIX

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/damageproto.pc.in
USE_LANGUAGES=		# empty

.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/fixesproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
