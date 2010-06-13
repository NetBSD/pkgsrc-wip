# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:08 thomasklausner Exp $
#

DISTNAME=	ibus-qt-1.3.0-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.googlecode.com/p/ibus/
COMMENT=	Qt IBus library and Qt input method plugin
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		ibus>=1.2:../../wip/ibus

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

# optionally, but required by configure.
#BUILD_DEPENDS+=		doxygen>=1.6:../../devel/doxygen
TOOLS_NOOP=		doxygen

.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
