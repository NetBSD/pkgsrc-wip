# $NetBSD$

DISTNAME=	michabo
PKGNAME=	michabo-${GIT_COMMITID}
CATEGORIES=	net
MASTER_SITES=	https://git.pleroma.social/kaniini/michabo/-/archive/${GIT_COMMITID}/michabo-${GIT_COMMITID}.tar.gz
GIT_COMMITID=	59f6168486352890cd9ef914ede23b1eccab5712
EXTRACT_USING=	bsdtar
# \todo: check if tagged 0.1 is recent enough to make it work.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.pleroma.social/kaniini/michabo
COMMENT=	Qt client for Pleroma and Mastodon
LICENSE=	gnu-gpl-v3
USE_LANGUAGES=	c++

QTDIR?=			${PREFIX}/qt5
PREPEND_PATH+=		${QTDIR}/bin
CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}

.for t in lupdate lrelease moc qmake uic
TOOLS_CREATE+=		${t}
TOOLS_PATH.${t}=	${QTDIR}/bin/${t}
.endfor

INSTALLATION_DIRS+=	bin
WRKSRC=			${WRKDIR}/${DISTNAME}-${GIT_COMMITID}

# Run-time dependency qt5 (modules: Core, Gui, WebSockets, Widgets, Network, DBus)
.include "../../devel/meson/build.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
#.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
#.include "../../x11/qt5-qttools/buildlink3.mk"
#.include "../../x11/qt5-qtx11extras/buildlink3.mk"
#.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
