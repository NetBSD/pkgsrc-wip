# $NetBSD: Makefile,v 1.2 2006/05/27 17:26:53 jeremy-c-reed Exp $
#

DISTNAME=		xinit-1.0.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/app/
COMMENT=		Utilities for starting the X Window System server

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

# on Linux, it could use mcookie from util-linux
# some openssl doesn't have that -hex
#CONFIGURE_ENV+=		MCOOKIE="/usr/bin/openssl rand -hex 16"
CONFIGURE_ENV+=		MCOOKIE="/bin/dd if=/dev/urandom bs=16 count=1 2>/dev/null | hexdump -e '\\\"%08x\\\"'"

.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
