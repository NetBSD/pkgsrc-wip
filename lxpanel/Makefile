# $NetBSD: Makefile,v 1.1.1.1 2009/10/22 00:38:43 jeremy-c-reed Exp $
#

DISTNAME=	lxpanel-0.3.999
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	SHORT_DESCRIPTION_OF_THE_PACKAGE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config
CONFIGURE_ARGS+=	  --with-plugins=none
# TODO: thermal is still built when "none"
# plugins may be comma separated:
# netstatus, netstat, volume, volumealsa, cpu, deskno, batt, kbled, xkb, thermal

PKGCONFIG_OVERRIDE+=	lxpanel.pc.in

# menu-cache, lxmenu-data

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
