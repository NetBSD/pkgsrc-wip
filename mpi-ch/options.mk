# $NetBSD: options.mk,v 1.1 2010/03/06 18:28:40 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpich
PKG_SUPPORTED_OPTIONS=	debug mpich-mpd
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-g=debug	# problems
INSTALL_UNSTRIPPED=	yes
.endif

# Allow coexistance of OpenMPI and libotf by disabling OpenMPI parts:
.if !empty(PKG_OPTIONS:Mmpich-mpd)
CONFLICTS+=	musicpd-[0-9]*	# installs bin/mpd
REPLACE_PYTHON+=	src/pm/mpd/*.py src/pm/mpd/test/*.py
CONFIGURE_ARGS+=	--with-pm=hydra:mpd:gforker
PLIST_SRC+=	PLIST.mpd
.include "../../lang/python/application.mk"
.endif

PLIST_SRC+=	PLIST
