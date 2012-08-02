# $NetBSD: Makefile,v 1.16 2012/08/02 00:26:08 asau Exp $

DISTNAME=		xrdp-0.5.0
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xrdp/}

MAINTAINER=		mwilhelmy@users.sourceforge.net
HOMEPAGE=		http://xrdp.sourceforge.net/
COMMENT=		Remote Desktop Protocol server
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		autoconf automake gmake
USE_LIBTOOL=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS=		xrdp sesman
# FIXME: are these really needed?
#RCD_SCRIPT_SRC.xrdp=	files/xrdp.sh
#RCD_SCRIPT_SRC.sesman=	files/sesman.sh

WRKSRC=			${WRKDIR}/xrdp
EGDIR=			${PREFIX}/share/examples/xrdp
#MAKE_ENV+=		DESTDIR=${DESTDIR:Q}${PREFIX:Q}
#MAKE_ENV+=		CFGDIR=${EGDIR:Q}
#MAKE_ENV+=		PIDDIR=/var/run
#MAKE_ENV+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
#MAKE_ENV+=		DOCDIR=${PREFIX:Q}/share/doc/xrdp
#MAKE_ENV+=		DLLIB=${BUILDLINK_LDADD.dl:Q}
#MAKE_ENV+=		CFGDIR=${PKG_SYSCONFDIR}
#MAKE_ENV+=		SHAREDIR=${PREFIX}/share
#
#INSTALL_ENV+=		BINDIR=${PREFIX}/bin
#INSTALL_ENV+=		LIBDIR=${PREFIX}/lib
#INSTALL_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
#INSTALL_ENV+=		ETCDIR=${PREFIX}/share/examples/xrdp
#INSTALL_ENV+=		PAMDIR=${PREFIX}/share/examples/pam.d
#INSTALL_ENV+=		SHAREDIR=${PREFIX}/share
INSTALL_ENV+=		sysconfdir=${EGDIR}
#AUTO_MKDIRS=		yes
INSTALLATION_DIRS=	share/xrdp share/examples/xrdp

PKG_SYSCONFSUBDIR=	xrdp
CONF_FILES+=		${EGDIR}/sesman.ini	${PKG_SYSCONFDIR}/sesman.ini
CONF_FILES+=		${EGDIR}/rsakeys.ini	${PKG_SYSCONFDIR}/rsakeys.ini
CONF_FILES+=		${EGDIR}/xrdp.ini	${PKG_SYSCONFDIR}/xrdp.ini

#PTHREAD_OPTS+=		native

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing variables in man-pages
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	docs/man/sesman.ini.5 docs/man/xrdp.ini.5
SUBST_FILES.man+=	docs/man/xrdp.8 docs/man/xrdp-sesman.8 docs/man/xrdp-sesrun.8
SUBST_SED.man=		-E -e 's,\$$\{(SESMAN|XRDP)_BIN_DIR\},${PREFIX:Q}/bin,g'
SUBST_SED.man+=		-e 's,\$$\{(SESMAN|XRDP)_CFG_DIR\},${PKG_SYSCONFDIR},g'
SUBST_SED.man+=		-e 's,\$$\{(SESMAN|XRDP)_LOG_DIR\},.,g' # FIXME
SUBST_SED.man+=		-e 's,\$$\{(SESMAN|XRDP)_PID_DIR\},/var/run,g'

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	sesman/env.c
SUBST_VARS.paths=	PREFIX

GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC}; ./bootstrap

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
