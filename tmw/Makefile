# $NetBSD: Makefile,v 1.10 2012/11/13 20:09:36 othyro Exp $
#

DISTNAME=	tmw-0.0.22.1
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=themanaworld/}

MAINTAINER=	Pseudo.Statistic@gmail.com
HOMEPAGE=	http://themanaworld.sourceforge.net/
COMMENT=	Free open source 2D MMORPG in development


GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--with-opengl
USE_TOOLS+=		pkg-config


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/guichan/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
