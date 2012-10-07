# $NetBSD: Makefile,v 1.10 2012/10/07 13:59:09 asau Exp $
#

DISTNAME=	urbanterror3
PKGNAME=	q3-urbanterror-3.0
WRKSRC=		${WRKDIR}/q3ut3
CATEGORIES=	games
MASTER_SITES=	ftp://mirror.candidhosting.com/pub/ut/ \
		http://box3.fsk405.org/q3ut3/ \
		http://fsk405.org/q3ut3/ \
		ftp://www.playdedicated.com/pub/sid/quake3/ \
		ftp://ftp.edome.net/online/clientit/ \
		http://atrivo.wofut.com/~zac/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.urbanterror.net/
COMMENT=	Quake III Arena Mod: Urban Terror for Linux

DEPENDS+=		quake3arena-[0-9]*:../../games/quake3arena

NO_SRC_ON_FTP=	no
NO_BIN_ON_FTP=	no

NO_CONFIGURE=	yes
BUILD_DIRS=	# empty

EMUL_PLATFORMS=		linux-i386

INSTALLATION_DIRS=	lib/lokigames/quake3arena/baseq3

do-install:
	${INSTALL_DATA} ${WRKSRC}/zq3ut3.pk3 \
		${DESTDIR}${PREFIX}/lib/lokigames/quake3arena/baseq3

.include "../../mk/bsd.pkg.mk"
