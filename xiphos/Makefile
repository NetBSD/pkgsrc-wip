# $NetBSD: Makefile,v 1.3 2012/11/12 16:51:39 othyro Exp $
#

DISTNAME=	xiphos-3.1.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomesword/}

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://gnomesword.sourceforge.net/
COMMENT=	Xiphos (formerly GnomeSword) is a Bible study tool using GTK
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=  	intltool gmake pkg-config
USE_LANGUAGES=	c c++

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/sword/buildlink3.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
