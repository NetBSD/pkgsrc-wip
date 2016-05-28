# $NetBSD: Makefile,v 1.6 2012/10/07 17:17:48 asau Exp $
#

DISTNAME=	trackballs-1.1.2
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=trackballs/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://trackballs.sourceforge.net/
COMMENT=	SDL-based Marble Madness clone


GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++ c99
USE_TOOLS+=		gmake m4 gettext intltool

DEPENDS+=	bash>=0:../../shells/bash
REPLACE_BASH+=	share/icons/installIcons

#CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-lintl -ljpeg

SUBST_CLASSES+=		share
SUBST_STAGE.share=	post-patch
SUBST_FILES.share=	share/Makefile.in
SUBST_SED.share=	-e 's|install -D|${INSTALL_DATA:Q}|'

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
