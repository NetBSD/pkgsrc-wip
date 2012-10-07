# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:08 asau Exp $

PKG_DESTDIR_SUPPORT=	none

.include "../../chat/xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-python-/}
COMMENT=	Python scripting plugin for xchat

DEPENDS+=	xchat>=2.0.0:../../chat/xchat

BUILD_DIRS=	plugins/python

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		ac_cv_path_pythonpath=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
