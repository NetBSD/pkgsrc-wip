# $NetBSD: Makefile,v 1.7 2011/10/30 17:03:26 noud4 Exp $
#

DISTNAME=	pidgin-festival-2.4
PKGREVISION=	3
CATEGORIES=	chat audio
MASTER_SITES=	http://downloads.sourceforge.net/pidgin-festival/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pidgin-festival.sourceforge.net/
COMMENT=	Pidgin plugin that interfaces with festival

DEPENDS+=		festival-[0-9]*:../../audio/festival
WRKSRC=			${WRKDIR}/pidgin-festival-2.4
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

CFLAGS+=		-DFESTIVAL_VOICES_PATH='"${PREFIX}/share/festival/lib/voices"'

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
