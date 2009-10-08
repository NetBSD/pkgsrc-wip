# $NetBSD: Makefile,v 1.1.1.1 2009/10/08 19:21:26 christtrekker Exp $
#

DISTNAME=	etoile-0.4.1
CATEGORIES=	meta-pkgs gnustep x11
MASTER_SITES=	http://download.gna.org/etoile/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://etoileos.com/
COMMENT=	Desktop environment built on GNUstep
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Etoile-0.4.1
USE_LANGUAGES=	c c++

DEPENDS+=	gnustep-make>=2.0.8:../../devel/gnustep-make
DEPENDS+=	gnustep-base>=1.18.0:../../devel/gnustep-base
DEPENDS+=	gnustep-gui>=0.16.0:../../x11/gnustep-gui
DEPENDS+=	gnustep-back>=0.16.0:../../x11/gnustep-back
DEPENDS+=	lemon>=1.0.0:../../devel/lemon
DEPENDS+=	postgresql>=8.3.0:../../databases/postgresql83

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
# libavcodec and libavformat   http://ffmpeg.mplayerhq.hu/
# OSS   http://www.opensound.com/
.include "../../audio/taglib/buildlink3.mk"
.include "../../multimedia/libmp4v2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
