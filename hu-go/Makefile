# $NetBSD: Makefile,v 1.5 2012/09/29 17:05:57 asau Exp $
#

DISTNAME=		hugo-2.11-preview
PKGNAME=		hu-go-2.11beta1
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		http://www.zeograd.com/download/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.zeograd.com/parse.php?src=hugof&path=0,1,
COMMENT=		PC Engine emulator (with CD support)

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/hugo-2.11
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

#CONFIGURE_ARGS+=	--with-ogg-support

#.include "../../audio/SDL_mixer/buildlink3.mk"
#.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
