# $NetBSD: Makefile,v 1.19 2006/04/27 23:15:02 jeremy-c-reed Exp $
#

DISTNAME=		imake-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/util/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/util/
COMMENT=		Imake and other utilities from modular X.org

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
