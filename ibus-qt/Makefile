# $NetBSD: Makefile,v 1.1.1.1 2009/12/06 07:06:29 obache Exp $
#

DISTNAME=	ibus-qt-1.2.0.20091206-Source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-Source//}
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.googlecode.com/p/ibus/
COMMENT=	Qt IBus library and Qt input method plugin
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-qt-[0-9]*

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
