# $NetBSD$
#

PKGNAME=		scummvm-fotaq-0
CATEGORIES=		games
MASTER_SITES=		https://www.scummvm.org/frs/extras/Flight%20of%20the%20Amazon%20Queen/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.scummvm.org/games/
COMMENT=		Flight Of The Amazon Queen
#LICENSE=		freeware license specified in readme.txt

WRKSRC=			${WRKDIR}

FOTAQDIR=	${PREFIX}/share/games/fotaq

INSTALLATION_DIRS=	bin

do-build:
	${SED} "s|@FOTAQDIR@|${FOTAQDIR}|" <${FILESDIR}/fotaq.sh \
		>${WRKDIR}/fotaq.sh

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
