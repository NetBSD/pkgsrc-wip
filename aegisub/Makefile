# $NetBSD: Makefile,v 1.1 2015/01/14 17:16:08 thomasklausner Exp $

DISTNAME=	aegisub-3.2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.aegisub.org/pub/archives/releases/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aegisub.org/
COMMENT=	Free, cross-platform tool for creating and modifying subtitles
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

#CONFIGURE_DIRS=	build
#CONFIGURE_SCRIPT=	../configure
PKGCONFIG_OVERRIDE+=	vendor/csri/csri.pc.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
