# $NetBSD: Makefile,v 1.2 2004/09/08 17:30:55 ianzag Exp $
#

DISTNAME=		amarok-1.0.2
CATEGORIES=		kde audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amarok/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://amarok.kde.org/
COMMENT=		amaroK is the audio player for KDE 

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --without-xine
CONFIGURE_ARGS+= --without-gstreamer
CONFIGURE_ARGS+= --without-nmm
CONFIGURE_ARGS+= --without-opengl
CONFIGURE_ARGS+= --without-included-sqlite

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
