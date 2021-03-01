# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	ksysguard-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://userbase.kde.org/KSysGuard
COMMENT=	Track and control the processes running in your system
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma5.mk"

CONFLICTS+=	kde-workspace4-[0-9]*

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

# ksysguardd/NetBSD/netdev.c and apm.c dont like the standard setting
SUBST_CLASSES+=		eat-std
SUBST_STAGE.eat-std=	post-configure
SUBST_FILES.eat-std=	_KDE_build/ksysguardd/NetBSD/CMakeFiles/libksysguardd.dir/flags.make
SUBST_SED.eat-std=	-e 's, -std=iso9899:1990 , ,g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	example/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_FULL_SYSCONFDIR}:{KDE_INSTALL_DATAROOTDIR}/examples/ksysguard:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}
CONF_FILES+=	${PREFIX}/share/examples/ksysguard/ksysguarddrc \
		${PKG_SYSCONFDIR}/ksysguarddrc

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/libksysguard/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
