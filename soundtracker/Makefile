# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:16 thomasklausner Exp $
#

DISTNAME=		soundtracker-0.6.8
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.soundtracker.org/dl/v0.6/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.soundtracker.org/
COMMENT=		Music tracker for XM and MOD files

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gettext
LIBS+=	${LIBOSSAUDIO}

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
