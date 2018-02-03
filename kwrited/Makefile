# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kwrited-${PLASMAVER}
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Plasma5 daemon listening for wall and write messages
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{AUTOSTART_INSTALL_DIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

PLIST_VARS+=		utempter noutempter
.if ${OPSYS} == "Linux" && exists(/usr/include/utempter.h)
PLIST.utempter=		yes
.elif ${OPSYS} == "FreeBSD" && exists(/usr/include/utempter.h)
PLIST.utempter=		yes
.else
PLIST.noutempter=	yes
CONF_FILES+=		${PREFIX}/share/examples/kde-xdg/autostart/kwrited-autostart.desktop \
			${PKG_SYSCONFDIR}/xdg/autostart/kwrited-autostart.desktop
.endif

.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
