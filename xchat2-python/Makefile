# $NetBSD: Makefile,v 1.3 2005/11/28 00:27:29 rillig Exp $

.include "../../chat/xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-python-/}

COMMENT=	Python scripting plugin for xchat

DEPENDS+=	xchat>=2.0.0:../../chat/xchat

BUILD_DIRS?=	${WRKSRC}/plugins/python

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		ac_cv_path_pythonpath=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
