# $NetBSD: Makefile,v 1.7 2012/12/30 20:00:56 roelants Exp $
#

DISTNAME=	elementary-1.7.4
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	E17 Widget Library
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gettext gmake pkg-config

PKGCONFIG_OVERRIDE=	elementary.pc.in

pre-configure:
		cd ${WRKSRC} && ./autogen.sh

MODULE_ARCH=	${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}-${LOWER_ARCH}
PLIST_SUBST=	MODULE_ARCH=${MODULE_ARCH}
PRINT_PLIST_AWK+=        { gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}") }

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../wip/eio/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/e_dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
