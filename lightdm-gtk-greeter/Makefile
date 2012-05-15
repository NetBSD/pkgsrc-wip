# $NetBSD: Makefile,v 1.1.1.1 2012/05/15 03:32:12 jeremy-c-reed Exp $
#

DISTNAME=	lightdm-gtk-greeter-1.1.5
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/lightdm-gtk-greeter/trunk/1.1.5/+download/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://launchpad.net/lightdm-gtk-greeter/trunk/1.1.5/+download/
COMMENT=	GTK+ greeter for LightDM
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

# Needed for launchpad
FETCH_USING=	curl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	intltool pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/lightdm/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
