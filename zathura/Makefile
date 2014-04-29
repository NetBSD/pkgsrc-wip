# $NetBSD: Makefile,v 1.9 2014/04/29 21:16:21 leot1990 Exp $

DISTNAME=	zathura-0.2.7
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
COMMENT=	PDF viewer with vi-like keybindings
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-docutils

.include "../../lang/python/pyversion.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/girara/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
