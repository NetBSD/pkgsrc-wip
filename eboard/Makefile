
# $NetBSD: Makefile,v 1.3 2005/02/04 14:30:34 thomasklausner Exp $
#

DISTNAME=		eboard-0.9.5
CATEGORIES=		wip games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=eboard/}

MAINTAINER=	 	zul@netbsd-fr.org
HOMEPAGE=		http://eboard.sourceforge.net/
COMMENT=		Chess Inteface for Unix chess engines

DEPENDS+=		sox-[0-9]*:../../audio/sox

USE_BUILDLINK3=		yes
USE_PERL5=		yes
USE_GNU_TOOLS+=		make

.include "../../mk/ossaudio.buildlink3.mk"

SUBST_CLASSES=		sox_dev
SUBST_STAGE.sox_dev=	post-patch
SUBST_FILES.sox_dev=	sound.cc
SUBST_SED.sox_dev=	-e 's,/dev/dsp,${DEVOSSAUDIO},g'
SUBST_MESSAGE.sox_dev=  "Fixing hard-coded device used by sox with ${DEVOSSAUDIO}"

do-configure:
	 cd ${WRKSRC} && ${PERL5} ${WRKSRC}/configure \
		--prefix=${PREFIX}  --libossaudio=${LIBOSSAUDIO} 

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
