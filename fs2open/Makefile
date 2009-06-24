# $NetBSD: Makefile,v 1.2 2009/06/24 08:07:58 yhardy Exp $
#

DISTNAME=	fs2_open-3.6.9
CATEGORIES=	games
MASTER_SITES=	http://fs2source.warpcore.org/exes/linux/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scp.indiegames.us/
COMMENT=	Freespace 2 source code project

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/fs2_open_r ${DESTDIR}${PREFIX}/bin/fs2_open

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
