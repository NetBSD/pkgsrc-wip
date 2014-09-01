# $NetBSD: Makefile,v 1.1 2014/09/01 21:59:49 thomasklausner Exp $

DISTNAME=	netpbm-10.67.03
CATEGORIES=	graphics
MASTER_SITES=	#
# manually created from svn checkout of
# svn checkout http://svn.code.sf.net/p/netpbm/code/advanced netpbm
# tar --exclude netpbm/.svn/\* -cvzf /archive/distfiles/netpbm-$VERSION.tar.gz netpbm
# where VERSION comes from reading netpbm/doc/HISTORY
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	Toolkit for conversion of images between different formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run gmake lex pax perl
USE_FEATURES=	snprintf
USE_GCC_RUNTIME=yes

INSTALL_TARGET=	install-dev install-run
MAKE_ENV+=	INSTALL=${INSTALL:Q} STRIPFLAG=${_STRIPFLAG_INSTALL:Q} \
		pkgdir=${STAGEDIR:Q} MACHINE=${MACHINE:Q}
MAKE_FILE=	GNUmakefile
REPLACE_PERL+=	converter/pbm/pbmtox10bm
REPLACE_PERL+=	editor/pnmflip
REPLACE_PERL+=	editor/pnmquant
REPLACE_PERL+=	editor/ppmfade
REPLACE_PERL+=	editor/ppmquant
REPLACE_PERL+=	editor/ppmshadow
REPLACE_PERL+=	generator/ppmrainbow
REPLACE_PERL+=	manweb
STAGEDIR=	${WRKDIR}/staging
WRKSRC=		${WRKDIR}/netpbm

LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	NETWORKLD=${LIBS:Q}

WRAPPER_REORDER_CMDS+=	reorder:l:rle:netpbm

# Several of the netpbm shell scripts use bashisms, so force using
# bash for all of the shell scripts.
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/sh
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	converter/other/anytopnm
REPLACE_FILES.bash+=	converter/other/pnmtoplainpnm
REPLACE_FILES.bash+=	converter/ppm/hpcdtoppm/hpcdtoppm
REPLACE_FILES.bash+=	converter/ppm/hpcdtoppm/pcdovtoppm
REPLACE_FILES.bash+=	editor/pamstretch-gen
REPLACE_FILES.bash+=	editor/pnmindex.sh
REPLACE_FILES.bash+=	editor/pnmmargin
REPLACE_FILES.bash+=	other/ppmtomap

SUBST_CLASSES+=		rgb_txt
SUBST_STAGE.rgb_txt=	post-patch
SUBST_MESSAGE.rgb_txt=	Configure RGB_TXT
SUBST_FILES.rgb_txt=	pm_config.in.h
SUBST_SED.rgb_txt+=	-e 's,@@PREFIX@@,${PREFIX},'

.include "../../mk/bsd.prefs.mk"

# Fiasco fails to compile on Darwin-8.x.
PLIST_VARS+=	fiasco
.if !empty(MACHINE_PLATFORM:MDarwin-8.*-*)
MAKE_ENV+=	BUILD_FIASCO=N
.else
PLIST.fiasco=	yes
.endif

.if ${OPSYS} == "Darwin"
MAKE_ENV+=	NETPBMLIBTYPE="dylib" NETPBMLIBSUFFIX="dylib"
.elif ${OPSYS} == "HPUX" && ${OBJECT_FMT} == "SOM"
MAKE_ENV+=	NETPBMLIBTYPE="unixshared" NETPBMLIBSUFFIX="sl"
.else
MAKE_ENV+=	NETPBMLIBTYPE="unixshared" NETPBMLIBSUFFIX="so"
.endif

.if ${OS_VARIANT} == "SCOOSR5"
LDFLAGS.SCO_SV+=	-lsocket
.endif

.if !empty(PKGSRC_COMPILER:Mido)
CPPFLAGS+=	-DSGI_IDO_CC
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/netpbm

post-extract:
	cd ${WRKSRC} && ${CP} config.mk.in config.mk
	${ECHO} "CFLAGS_SHLIB = -fPIC" >> ${WRKSRC}/config.mk

pre-install:
	${RM} -fr ${STAGEDIR}

post-install:
	cd ${STAGEDIR} && 					\
	${MV} link/* lib && 					\
	${RM} -rf link man/web && 				\
	${MKDIR} share &&					\
	${MV} misc share/netpbm && 				\
	${CHOWN} -R ${BINOWN}:${BINGRP} . &&			\
	pax -rwpppm . ${DESTDIR}${PREFIX}
	${RM} -fr ${STAGEDIR}

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
