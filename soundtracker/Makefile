# $NetBSD: Makefile,v 1.1.1.1 2004/06/27 21:16:58 poppnk Exp $
#

DISTNAME=		soundtracker-0.6.6
CATEGORIES=		wip audio
MASTER_SITES=		http://www.soundtracker.org/dl/v0.6/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.soundtracker.org/
COMMENT=		Music tracker for XM and MOD files

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
LIBS+=	${LIBOSSAUDIO}

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
