# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 00:09:30 minskim Exp $

.include "../../chat/xchat2/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-python-/}

COMMENT=	Python scripting plugin for xchat2

DEPENDS+=	xchat>=2.0.0:../../chat/xchat2

BUILD_DIRS?=	${WRKSRC}/plugins/python

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		ac_cv_path_pythonpath=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
