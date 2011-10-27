# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 07:24:54 tomasbodzar Exp $
#

DISTNAME=	zathura-0.0.8.4
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
COMMENT=	PDF viewer with vi-like keybindings
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes
DEPENDS+=	py26-docutils-[0-9]*:../../textproc/py-docutils

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
