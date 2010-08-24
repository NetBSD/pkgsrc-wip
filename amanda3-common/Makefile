# $NetBSD: Makefile,v 1.1.1.1 2010/08/24 02:40:35 schnoebe Exp $

PKGNAME=		amanda-common-${VERS}
SVR4_PKGNAME=		amaco

COMMENT=		Common libraries and binaries for Amanda

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../wip/amanda3-common/Makefile.common"

.if ${OPSYS} == "NetBSD"
CPPFLAGS=		# empty
.elif ${OPSYS} == "SunOS"
CPPFLAGS+=		-D_LARGEFILE64_SOURCE
.endif

CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-ndmp
CONFIGURE_ARGS+=	--without-gnuplot

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

PKG_GROUPS=		${AMANDA_GROUP}
PKG_USERS=		${AMANDA_USER}:${AMANDA_GROUP}

PKG_GECOS.${AMANDA_USER}=	Amanda pseudo-user
PKG_SHELL.${AMANDA_USER}=	${SH}

OWN_DIRS_PERMS=		${AMANDA_VAR} ${AMANDA_USER} ${AMANDA_GROUP} 0700
OWN_DIRS_PERMS+=	${AMANDA_VAR}/gnutar-lists  ${AMANDA_USER} ${AMANDA_GROUP} 0700
BUILD_DEFS+=		AMANDA_VAR AMANDA_USER AMANDA_GROUP

INSTALL_MAKE_FLAGS+=	SETUID_GROUP=${ROOT_GROUP}

.include "../../mk/bsd.pkg.mk"
