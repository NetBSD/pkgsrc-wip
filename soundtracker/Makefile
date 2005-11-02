# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:27 thomasklausner Exp $
#

DISTNAME=		soundtracker-0.6.6
CATEGORIES=		audio
MASTER_SITES=		http://www.soundtracker.org/dl/v0.6/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.soundtracker.org/
COMMENT=		Music tracker for XM and MOD files

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
LIBS+=	${LIBOSSAUDIO}

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
