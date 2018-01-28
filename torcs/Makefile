# $NetBSD: Makefile,v 1.7 2012/10/07 17:17:44 asau Exp $
#

DISTNAME=	torcs-1.3.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=torcs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.torcs.org/
COMMENT=	The Open Racing Car Simulator
LICENSE=	gnu-gpl-v2

RESTRICTED=		Files too large.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	bash gmake

CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib${LIBABISUFFIX:Q}

REPLACE_BASH+=	robotgen
REPLACE_BASH+=	src/linux/torcs.in
REPLACE_BASH+=	src/tools/accc/accc.in
REPLACE_BASH+=	src/tools/nfsperf/nfsperf.in
REPLACE_BASH+=	src/tools/texmapper/texmapper.in
REPLACE_BASH+=	src/tools/nfs2ac/nfs2ac.in
REPLACE_BASH+=	src/tools/trackgen/trackgen.in
REPLACE_BASH+=	src/modules/telemetry/telemetry.sh
REPLACE_BASH+=	data/tracks/road/ole-road-1/generate.sh

SUBST_CLASSES+=			fix-bash
SUBST_STAGE.fix-bash=		pre-configure
SUBST_MESSAGE.fix-bash=		Fixing path to bash interpreter.
SUBST_FILES.fix-bash=		Make-default.mk src/linux/torcs.in
SUBST_SED.fix-bash=		-e 's,@BASH@,${BASH},g'

SUBST_CLASSES+=			fix-mkdir
SUBST_STAGE.fix-mkdir=		pre-configure
SUBST_MESSAGE.fix-mkdir=	Fixing mkdir use in installation scripts.
SUBST_FILES.fix-mkdir=		mkinstalldirs
SUBST_SED.fix-mkdir=		-e 's,@INSTALL_DATA_DIR@,${INSTALL_DATA_DIR},g'

BUILD_TARGET=
INSTALL_TARGET=		install datainstall

#pre-configure:
#	- cd ${WRKSRC} && ${RM} Make-config

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
