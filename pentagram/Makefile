# $NetBSD$
#

GITHUB_PROJECT=	pentagram
GITHUB_TAG=	e90df6d82b9e8eaf5725a2d4cc117121ce39f5a5
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-20161127
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=pentagram-u8/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pentagram.sf.net/
COMMENT=	A reimplementation of the Ultima 8 game engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake gmake perl
REPLACE_PERL+=	system/auto/genrules.pl

INSTALLATION_DIRS+=	share/doc/pentagram

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pentagram

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
