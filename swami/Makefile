# $NetBSD: Makefile,v 1.9 2005/08/11 10:08:23 absd Exp $
#

DISTNAME=		swami-0.9.2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swami/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://swami.sourceforge.net/
COMMENT=		SoundFont2 instrument editor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LOCALEDIR=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
