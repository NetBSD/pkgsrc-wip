# $NetBSD: Makefile,v 1.7 2012/11/13 20:26:27 othyro Exp $

DISTNAME=		boinc
PKGNAME=		boinc-client-1
PKGREVISION=		1
CATEGORIES=		net

COMMENT=		The BOINC distributed computing application


GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoheader autoconf automake m4 pkg-config gmake
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--disable-server
BUILD_DIRS=		client
SHLIBTOOL_OVERRIDE=	m4/libtool.m4

.include "../../wip/boinc-lib/Makefile.common"

CVS_REPOSITORIES=	boinc

FILESDIR=		files
FILES_SUBST+=		BOINC_USER=${BOINC_USER:Q}
FILES_SUBST+=		BOINC_GROUP=${BOINC_GROUP:Q}
FILES_SUBST+=		BOINC_DIR=${BOINC_DIR:Q}
PKG_GROUPS=		${BOINC_GROUP}
PKG_USERS=		${BOINC_USER}:${BOINC_GROUP}
PKG_HOME.${BOINC_USER}=	${BOINC_DIR}
PKG_SHELL.${BOINC_USER}= ${SH}
RCD_SCRIPTS=		boinc

pre-configure:
	cd ${WRKSRC} &&			\
	aclocal -I m4 && autoheader &&	\
	automake && autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rc.d
	${INSTALL_DATA} ${FILESDIR}/boinc.sh ${PREFIX}/share/examples/rc.d/boinc

.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgui)
BUILD_DIRS+=		clientgui
.endif

.include "../../wip/boinc-lib/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
