# $NetBSD: Makefile,v 1.9 2006/08/14 14:18:55 obache Exp $
#

DISTNAME=		gtick-0.3.10
CATEGORIES=		audio
MASTER_SITES=		http://www.antcom.de/gtick/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.antcom.de/gtick/
COMMENT=		GTK+ metronome

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		msgfmt pkg-config bison

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_FILES.dsp=	src/globals.h
SUBST_SED.dsp=		-e 's|/dev/dsp|${DEVOSSAUDIO}|'

.include "../../x11/gtk2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
