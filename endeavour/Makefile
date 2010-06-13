# $NetBSD: Makefile,v 1.12 2010/06/13 22:47:03 thomasklausner Exp $
#

DISTNAME=	endeavour-2.8.5
#PKGREVISION=	1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.battlefieldlinux.com/wolfpack/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.battlefieldlinux.com/wolfpack/Endeavour2/
COMMENT=	File manager and image browser

DEPENDS+=	e2fsprogs>=1.32:../../sysutils/e2fsprogs
DEPENDS+=	unarj>=2.43:../../archivers/unarj
DEPENDS+=	lha>=114:../../archivers/lha
DEPENDS+=	unrar>=3.0:../../archivers/unrar
DEPENDS+=	wget>=1.10:../../net/wget

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash gzip:run tar:run

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing prefixes.
SUBST_FILES.prefix=	endeavour2/platforms.ini
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

SUBST_CLASSES+=		shell
SUBST_STAGE.shell=	pre-configure
SUBST_MESSAGE.shell=	Fixing make shell.
SUBST_FILES.shell=	endeavour2/makefile_append.ini
SUBST_SED.shell=	-e "s|@BASH@|${BASH}|g"

SUBST_CLASSES+=		inst
SUBST_STAGE.inst=	pre-configure
SUBST_MESSAGE.inst=	Fixing install prefixes.
SUBST_FILES.inst=	endeavour2/download.front/Makefile \
			endeavour2/format.front/Makefile \
			endeavour2/fsck.front/Makefile \
			endeavour2/hedit/Makefile \
			endeavour2/lib/demos/Makefile \
			endeavour2/lib/Makefile \
			endeavour2/sysinfo/Makefile \
			endeavour2/tedit/Makefile \
			endeavour2/utils/Makefile \
			endeavour2/ziptool.front/Makefile
SUBST_SED.inst=		-e "s|/usr|${PREFIX}|g"

# ${PREFIX}/${PKGMANDIR} is preferred, but endeavour doesnt use it
END_MAN_DIR=	${PREFIX}/${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ./configure UNIX --prefix=${PREFIX}

post-install:
	bunzip2 -f ${END_MAN_DIR}/endeavour2-config.1.bz2
	bunzip2 -f ${END_MAN_DIR}/endeavour2.1.bz2
	bunzip2 -f ${END_MAN_DIR}/hedit.1.bz2
	bunzip2 -f ${END_MAN_DIR}/sysinfo.endeavour2.1.bz2
	bunzip2 -f ${END_MAN_DIR}/tedit.1.bz2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../wip/xar/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
