# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:19 thomasklausner Exp $
#

DISTNAME=	dssi-0.9.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dssi/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://dssi.sourceforge.net/
COMMENT=	API for audio processing plugins

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	dssi.pc.in

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../wip/libdssialsacompat/buildlink3.mk"
.include "../../wip/liblo/buildlink3.mk"
#.include "../../x11/qt3-libs/buildlink3.mk"
#.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
