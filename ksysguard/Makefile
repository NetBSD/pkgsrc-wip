# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	ksysguard-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://userbase.kde.org/KSysGuard
COMMENT=	Track and control the processes running in your system
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma5.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

# For the moment dont find libpcap as NetBSD9 doesn't have
# pcap/sll.h 
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_libpcap:BOOL=TRUE
#.if !exists(/usr/include/pcap/sll.h)
#PREFER.libpcap=	pkgsrc
#.endif

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
#.include "../../net/libpcap/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/libksysguard/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
