# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:04 thomasklausner Exp $
#

DISTNAME=	gemrb-0.6.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gemrb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gemrb.sourceforge.net/
COMMENT=	Open Source clone of the Infinity Engine
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILDLINK_TRANSFORM+=	rm:-Werror
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/gemrb

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
