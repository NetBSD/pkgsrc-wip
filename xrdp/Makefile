# $NetBSD: Makefile,v 1.19 2012/10/07 20:11:10 asau Exp $

DISTNAME=		xrdp-0.5.0
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xrdp/}

MAINTAINER=		mwilhelmy@users.sourceforge.net
HOMEPAGE=		http://xrdp.sourceforge.net/
COMMENT=		Remote Desktop Protocol server
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		autoconf automake gmake
USE_LIBTOOL=		yes

RCD_SCRIPTS=		xrdp sesman
RCD_SCRIPT_SRC.xrdp=	files/xrdp.sh
RCD_SCRIPT_SRC.sesman=	files/sesman.sh

WRKSRC=			${WRKDIR}/xrdp
EGDIR=			${PREFIX}/share/examples/xrdp
AUTO_MKDIRS=		yes
MAKE_DIRS=		share/examples/pam.d
INSTALLATION_DIRS=	share/xrdp share/examples/xrdp

PKG_SYSCONFSUBDIR=	xrdp
CONF_FILES+=		${EGDIR}/sesman.ini	${PKG_SYSCONFDIR}/sesman.ini
CONF_FILES+=		${EGDIR}/rsakeys.ini	${PKG_SYSCONFDIR}/rsakeys.ini
CONF_FILES+=		${EGDIR}/xrdp.ini	${PKG_SYSCONFDIR}/xrdp.ini

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing variables in man-pages
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	docs/man/sesman.ini.5 docs/man/xrdp.ini.5
SUBST_FILES.man+=	docs/man/xrdp.8 docs/man/xrdp-sesman.8 docs/man/xrdp-sesrun.8
SUBST_SED.man=		-E -e 's,\$$\{(SESMAN|XRDP)_BIN_DIR\},${PREFIX}/bin,g'
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
	set -e; cd ${WRKSRC}; ${CONFIG_SHELL} bootstrap

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
