# $NetBSD: Makefile,v 1.1 2013/03/03 17:55:48 othyro Exp $
#

DISTNAME=	uget-2.0.10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=urlget/}

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://ugetdm.com
COMMENT=	Open Source download manager application developed with GTK+
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	bash intltool msgfmt msgmerge perl pkg-config xgettext
CONFIG_SHELL=	${BASH}

.include "options.mk"

# XXX verifypc: appindicator3-0.1 not found
BUILDLINK_DEPMETHOD.glib2=	build
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
