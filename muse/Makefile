# $NetBSD: Makefile,v 1.1.1.1 2003/05/14 06:39:29 xtraeme Exp $
#

DISTNAME=	MuSE-0.8.1
PKGNAME=	${DISTNAME:C/MuSE/muse/}
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/muse/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://muse.dyne.org/
COMMENT=	Multiple Streaming Engine

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_OSS=		yes
USE_NCURSES=		yes

CONFIGURE_ARGS+=	--with-rubik
CONFIGURE_ARGS+=	--enable-debug=no

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
