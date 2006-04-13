# $NetBSD: Makefile,v 1.1.1.1 2006/04/13 02:18:59 jeremy-c-reed Exp $

DISTNAME=	libXft-2.1.8.2
CATEGORIES=	fonts x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	xft.pc.in

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
