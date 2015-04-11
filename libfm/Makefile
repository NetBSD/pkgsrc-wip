# $NetBSD: Makefile,v 1.9 2015/04/11 18:01:27 krytarowski Exp $
#

DISTNAME=	libfm-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	File management library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool pkg-config

CONF_FILES+=	etc/xdg/libfm/libfm.conf

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
