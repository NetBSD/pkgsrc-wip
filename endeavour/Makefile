# $NetBSD: Makefile,v 1.1.1.1 2006/07/31 22:15:44 dhowland Exp $
#

DISTNAME=	endeavour-2.5.7
CATEGORIES=	sysutils
MASTER_SITES=	http://wolfpack.twu.net/users/wolfpack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://wolfpack.twu.net/Endeavour2/
COMMENT=	File manager and image browser

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash

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
			endeavour2/lib/Makefile \
			endeavour2/sysinfo/Makefile \
			endeavour2/utils/Makefile \
			endeavour2/ziptool.front/Makefile
SUBST_SED.inst=		-e "s|/usr|${PREFIX}|g"

do-configure:
	cd ${WRKSRC} && ./configure UNIX --prefix=${PREFIX}

.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
