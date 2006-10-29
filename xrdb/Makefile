# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:58 shattered Exp $
#

DISTNAME=		xrdb-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X server resource database utility

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
