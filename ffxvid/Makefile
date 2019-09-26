# $NetBSD$

DISTNAME=	ffxvid-1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	https://downloads.sourceforge.net/sourceforge/ffxvid/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://downloads.sourceforge.net/sourceforge/ffxvid
COMMENT=	Small script to encode to Xvid video
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

do-build:

do-install:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} DESTDIR=${DESTDIR} MANDIR=${PREFIX}/${PKGMANDIR}


.include "../../mk/bsd.pkg.mk"
