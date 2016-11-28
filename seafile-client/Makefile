# $NetBSD$

CATEGORIES=	net
GITHUB_PROJECT=	seafile-client
VERSION=	6.0.0
DISTNAME=	v${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}
GITHUB_TAG=	v${VERSION}

DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile client
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}

USE_CMAKE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config cmake

.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/seafile-ccnet/buildlink3.mk"
.include "../../wip/seafile-libsearpc/buildlink3.mk"
.include "../../wip/seafile-daemon/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-sqlite3/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
