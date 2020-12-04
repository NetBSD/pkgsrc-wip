# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	libksysguard-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://userbase.kde.org/KSysGuard
COMMENT=	Library to track and control the processes running in your system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	rt
.else
RT_LIB_SCHED=	# empty
.endif
CMAKE_ARGS+=	-DRT_LIB_SCHED=${RT_LIB_SCHED}
CMAKE_ARGS.NetBSD+=	-DKVM_LIB=kvm

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/libksysguard

SUBST_CLASSES+=		qlc
SUBST_STAGE.qlc=	pre-configure
SUBST_MESSAGE.qlc=	Move to new KDE location
SUBST_FILES.qlc=	CMakeLists.txt
SUBST_SED.qlc=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_LOGGINGCATEGORIESDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/libksysguard/org.kde.ksysguard.processlisthelper.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ksysguard.processlisthelper.conf

INSTALLATION_DIRS+=	share/examples/libksysguard

.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
