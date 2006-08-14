# $NetBSD: Makefile,v 1.7 2006/08/14 22:46:23 thomasklausner Exp $
#

DISTNAME=		StepMania-3.9-src
PKGNAME=		stepmania-3.9
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stepmania/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.stepmania.com/stepmania/
COMMENT=		Music/rhythm game (Dance Dance Revolution) simulator

WRKSRC=			${WRKDIR}/StepMania-3.9-src
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake autoconf pkg-config

post-extract:
	${CP} ${FILESDIR}/arch_bsd.h ${WRKSRC}/src/arch

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
