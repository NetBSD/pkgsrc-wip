# $NetBSD: Makefile,v 1.3 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	gsview-4.9
CATEGORIES=	print
MASTER_SITES=	http://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum

MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://pages.cs.wisc.edu/~ghost/
COMMENT=	Graphical interface for ghostscript

LICENSE=		afpl-license
RESTRICTED=		Commercial distribution prohibited in most cases.
# CDROM distribution may be acceptable in some cases, but not all, so
# the variables are set.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake pkg-config gs:run

SUBST_CLASSES+=		pstotext
SUBST_STAGE.pstotext=	do-configure
SUBST_FILES.pstotext=	srcunx/gvxdll.c
SUBST_SED.pstotext=	-e 's|@PSTOTEXT_CMD@|${PSTOTEXT_DIR}/bin/pstotext|'

SUBST_CLASSES+=	gs
SUBST_STAGE.gs=	do-configure
SUBST_FILES.gs=	src/gvcver.h srcunx/gvx.h srcunx/gvxdll.c
SUBST_SED.gs=	-e 's|@GS_CMD@|${TOOLS_PATH.gs}|'

MAKE_FILE=		srcunx/unx.mak
BUILD_MAKE_FLAGS+=	GSVIEW_ROOT=${PREFIX}
BUILD_MAKE_FLAGS+=	prefix=# empty
BUILD_MAKE_FLAGS+=	CC=${CC}
BUILD_MAKE_FLAGS+=	CDEBUG=# empty
BUILD_MAKE_FLAGS+=	PFLAGS="-DMULTITHREAD ${PTHREAD_CFLAGS}"
BUILD_MAKE_FLAGS+=	GSVIEW_ETCPATH=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	GSVIEW_ROOT=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	prefix=# empty
INSTALL_MAKE_FLAGS+=	PLINK="${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}"
INSTALL_MAKE_FLAGS+=	INSTALL="${INSTALL_DATA}"
INSTALL_MAKE_FLAGS+=	INSTALL_EXE="${INSTALL_PROGRAM}"
INSTALL_MAKE_FLAGS+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

OWN_DIRS=	${PKG_SYSCONFDIR}/gsview
EGDIR=		${PREFIX}/share/examples/gsview
CONF_FILES=	${EGDIR}/printer.ini ${PKG_SYSCONFDIR}/gsview/printer.ini

INSTALLATION_DIRS+=	share/examples/gsview

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/src/printer.ini ${DESTDIR}${EGDIR}/printer.ini


DEPENDS+=	pstotext-[0-9]*:../../converters/pstotext

.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
