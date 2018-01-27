# $NetBSD: Makefile,v 1.14 2013/06/14 13:37:56 noud4 Exp $
#

DISTNAME=	pidgin-festival-2.4
PKGREVISION=	7
CATEGORIES=	chat audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-festival/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pidgin-festival.sourceforge.net/
COMMENT=	Pidgin plugin that interfaces with festival
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
DEPENDS+=		festival-[0-9]*:../../audio/festival
WRKSRC=			${WRKDIR}/pidgin-festival-2.4
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake gm4 msgfmt
USE_TOOLS+=		pkg-config xgettext

CFLAGS+=		-DFESTIVAL_VOICES_PATH='"${PREFIX}/share/festival/lib/voices"'

INSTALLATION_DIRS=	lib/purple-2 share/locale/es/LC_MESSAGES share/locale/pt_BR/LC_MESSAGES share/locale/ru/LC_MESSAGES

.include "options.mk"

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
