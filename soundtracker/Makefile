# $NetBSD: Makefile,v 1.5 2007/12/04 00:47:10 netcap Exp $
#

DISTNAME=		soundtracker-0.6.8
CATEGORIES=		audio
MASTER_SITES=		http://www.soundtracker.org/dl/v0.6/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.soundtracker.org/
COMMENT=		Music tracker for XM and MOD files

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gettext
USE_DIRS+=		xdg-1.4
LIBS+=	${LIBOSSAUDIO}

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
