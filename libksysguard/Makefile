# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	libksysguard-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://userbase.kde.org/KSysGuard
COMMENT=	Library to track and control the processes running in your system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kde5/plasma.mk"

CONFLICTS+=	kde-workspace4-[0-9]*

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../wip/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	rt
.else
RT_LIB_SCHED=	# empty
.endif
CMAKE_ARGS+=	-DRT_LIB_SCHED=${RT_LIB_SCHED}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/libksysguard/org.kde.ksysguard.processlisthelper.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ksysguard.processlisthelper.conf

INSTALLATION_DIRS+=	share/examples/libksysguard

post-install:
	mv ${DESTDIR}/etc/dbus-1/system.d/org.kde.ksysguard.processlisthelper.conf \
	${DESTDIR}${PREFIX}/share/examples/libksysguard/

.include "../../wip/plasma-framework/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
