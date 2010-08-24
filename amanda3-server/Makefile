# $NetBSD: Makefile,v 1.1.1.1 2010/08/24 03:28:51 schnoebe Exp $

PKGNAME=		amanda-server-${VERS}
SVR4_PKGNAME=		amase

COMMENT=		Server part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=		awk:run

.include "../../mk/bsd.prefs.mk"
.include "../../wip/amanda3-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

.include "../../wip/amanda3-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
