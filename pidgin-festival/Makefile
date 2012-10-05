# $NetBSD: Makefile,v 1.10 2012/10/05 11:31:51 asau Exp $
#

DISTNAME=	pidgin-festival-2.4
PKGREVISION=	5
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

CFLAGS+=                -DFESTIVAL_VOICES_PATH='"${PREFIX}/share/festival/lib/voices"'

INSTALLATION_DIRS=	lib/purple-2 share/locale/es/LC_MESSAGES share/locale/pt_BR/LC_MESSAGES share/locale/ru/LC_MESSAGES

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
