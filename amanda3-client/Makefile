# $NetBSD: Makefile,v 1.1.1.1 2010/08/24 02:43:11 schnoebe Exp $
#

PKGNAME=		amanda-client-${VERS}
SVR4_PKGNAME=		amacl

COMMENT=		Client part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		awk:run

.include "../../mk/bsd.prefs.mk"
.include "../../wip/amanda3-common/Makefile.common"
.include "../../wip/amanda3-common/buildlink3.mk"
.include "../../wip/amanda3-common/options.mk"

CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--without-ndmp

# Prevent configure script from finding unnecessary libraries.  We'll patch
# the amrecover Makefile to add the readline libraries as it's the only
# program that uses readline. (XXX: incorrect, does not happen)
#
# CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
# CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
# CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
# CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
# CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

.include "../../mk/bsd.pkg.mk"
