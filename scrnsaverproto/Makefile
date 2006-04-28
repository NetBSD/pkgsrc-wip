# $NetBSD: Makefile,v 1.3 2006/04/28 06:29:36 jeremy-c-reed Exp $
#

DISTNAME=		scrnsaverproto-1.1.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		ScrnSaver extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/scrnsaverproto.pc.in
USE_LANGUAGES=		# empty

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
