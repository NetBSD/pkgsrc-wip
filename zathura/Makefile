# $NetBSD: Makefile,v 1.6 2013/09/03 17:40:00 shattered Exp $
#

DISTNAME=	zathura-0.2.3
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
COMMENT=	PDF viewer with vi-like keybindings
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/girara/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
