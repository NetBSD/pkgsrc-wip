# $NetBSD: Makefile,v 1.4 2015/04/09 03:09:36 krytarowski Exp $

DISTNAME=	caja-dropbox-1.12.0
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obach@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Dropbox Caja extension
LICENSE=	cc-by-nd-v3.0-license AND gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

REPLACE_PYTHON=	caja-dropbox.in

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
