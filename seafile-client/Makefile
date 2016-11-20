# $NetBSD$
PKGNAME=	seafile-client-6.0.0
CATEGORIES=	net
GHCOMMIT=	92b27c6953419508a0df7e28a286b79e914fed4f
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/seafile-client/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile client
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	seafile-client
WRKSRC=		${WRKDIR}/seafile-client-${GHCOMMIT}

#USE_LIBTOOL=	yes
USE_CMAKE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config cmake qmake

#INSTALL_MAKE_FLAGS=	INSTALL_ROOT=${DESTDIR}

DEPENDS+=	seafile-daemon-6.0.0{,nb*}:../../wip/seafile-daemon
#DEPENDS+=	qt5-qtbase-*:../../x11/qt5-qtbase
DEPENDS+=	sqlite3-*:../../databases/sqlite3

.include "../../mk/bsd.pkg.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
