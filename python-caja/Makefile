# $NetBSD: Makefile,v 1.5 2015/04/09 22:07:26 krytarowski Exp $

DISTNAME=	python-caja-1.12.0
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Python bindings for libcaja-extension
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config intltool

PKGCONFIG_OVERRIDE+=	caja-python.pc.in

.include "../../wip/caja/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
