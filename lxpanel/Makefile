# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:11 thomasklausner Exp $
#

DISTNAME=	lxpanel-0.3.999
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	SHORT_DESCRIPTION_OF_THE_PACKAGE

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

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
.include "../../wip/menu-cache/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
