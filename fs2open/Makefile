# $NetBSD: Makefile,v 1.8 2013/09/08 20:21:09 yhardy Exp $
#

PKGNAME=	fs2_open-3.7.0
DISTNAME=	fs2_open_3_7_0_src
CATEGORIES=	games
MASTER_SITES=	http://swc.fs2downloads.com/builds/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scp.indiegames.us/
COMMENT=	Freespace 2 source code project

WRKSRC=		${WRKDIR}/fs2_open_3_7_0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf automake pkg-config

INSTALLATION_DIRS=	bin

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; automake -a --foreign -i; autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/fs2_open_3.7.0 ${DESTDIR}${PREFIX}/bin/fs2_open

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
