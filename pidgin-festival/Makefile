# $NetBSD: Makefile,v 1.8 2011/11/07 23:00:19 othyro Exp $
#

DISTNAME=	pidgin-festival-2.4
PKGREVISION=	4
CATEGORIES=	chat audio
MASTER_SITES=	http://downloads.sourceforge.net/pidgin-festival/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pidgin-festival.sourceforge.net/
COMMENT=	Pidgin plugin that interfaces with festival
LICENSE=	gnu-gpl-v2

DEPENDS+=		festival-[0-9]*:../../audio/festival
WRKSRC=			${WRKDIR}/pidgin-festival-2.4
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

CFLAGS+=                -DFESTIVAL_VOICES_PATH='"${PREFIX}/share/festival/lib/voices"'

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
