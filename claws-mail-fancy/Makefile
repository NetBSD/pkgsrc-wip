# $NetBSD: Makefile,v 1.8 2015/07/14 19:45:44 roelants Exp $
#

PLUGIN_NAME=    fancy
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	dieter.NetBSD@pandora.be
COMMENT=	Renders HTML e-mail using the WebKit library

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin
CONFIGURE_ARGS+=	--disable-libravatar-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../www/webkit24-gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
