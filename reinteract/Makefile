# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:15 thomasklausner Exp $
#

DISTNAME=	reinteract-0.5.0
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.reinteract.org/download/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.reinteract.org/trac/
COMMENT=	Reinteract is a system for interactive experimentation with Python

DEPENDS+=	sox>=14.0.1:../../audio/sox
DEPENDS+=	epydoc>=2.1:../../devel/epydoc
#DEPENDS+=	${PYPKGPREFIX}-scipy-0.6.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-configobj>=0.4.3:../../wip/py-configobj

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

REPLACE_PYTHON+=	bin/reinteract.in

PY_PATCHPLIST=	yes

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
