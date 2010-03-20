# $NetBSD: Makefile,v 1.1.1.1 2010/03/20 14:06:09 pallegra Exp $
#

DISTNAME=	modplugplay-1.0
CATEGORIES=	audio
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/modplugplay/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://gnu.ethz.ch/linuks.mine.nu/modplugplay/
COMMENT=	Commandline music mod player using libmodplug
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

LDFLAGS+=	-lmodplug ${LIBOSSAUDIO}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	modplugplay.c
SUBST_SED.paths=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},'

do-build:
	${CXX} ${WRKSRC}/modplugplay.c ${CFLAGS} ${LDFLAGS} \
		-o ${WRKSRC}/modplugplay

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugplay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/modplugplay.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../mk/oss.buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
