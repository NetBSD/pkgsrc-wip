# $NetBSD: Makefile,v 1.11 2006/09/14 18:47:43 dhowland Exp $
#

DISTNAME=		eboard-0.9.5
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=eboard/}

MAINTAINER=	 	zul@netbsd-fr.org
HOMEPAGE=		http://eboard.sourceforge.net/
COMMENT=		Chess Inteface for Unix chess engines

DEPENDS+=		sox-[0-9]*:../../audio/sox

USE_PERL5=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../mk/oss.buildlink3.mk"

SUBST_CLASSES+=		sox_dev
SUBST_STAGE.sox_dev=	post-patch
SUBST_FILES.sox_dev=	sound.cc
SUBST_SED.sox_dev=	-e 's,/dev/dsp,${DEVOSSAUDIO},g'
SUBST_MESSAGE.sox_dev=  Fixing hard-coded device used by sox with ${DEVOSSAUDIO}

do-configure:
	 cd ${WRKSRC} && ${PERL5} ${WRKSRC}/configure \
		--prefix=${PREFIX}  --libossaudio=${LIBOSSAUDIO}

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
