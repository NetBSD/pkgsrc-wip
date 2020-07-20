# $NetBSD$

DISTNAME=	starfighter-2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=pr-starfighter/}
GITHUB_TAG=	v2.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pr-starfighter.github.io/
COMMENT=	Side-scrolling shoot 'em up space game
LICENSE=	gnu-gpl-v3 AND public-domain AND cc-by-sa-v3.0 AND cc0-1.0-universal AND ipafont

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake gettext gmake msgfmt pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

pre-build:
	# do the same as ${WRKSRC}/locale/build.py but without the python dependency
	cd ${WRKSRC}/locale && \
		for po in *.po; do \
			mkdir $${po%.po}/LC_MESSAGES; \
			msgfmt -o $${po%.po}/LC_MESSAGES/pr-starfighter.mo $$po; \
		done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
