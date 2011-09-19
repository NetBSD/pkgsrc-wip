# $NetBSD: Makefile,v 1.1.1.1 2011/09/19 07:00:30 ryo-on Exp $
#

DISTNAME=	viewnior-1.1
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/xsisqox/Viewnior/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://xsisqox.github.com/Viewnior/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	intltool pkg-config gmake

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
