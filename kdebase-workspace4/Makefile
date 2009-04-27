# $NetBSD: Makefile,v 1.23 2009/04/27 18:21:24 thomasklausner Exp $

DISTNAME=	kdebase-workspace-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	base workspace for the KDE 4 integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

DISTFILES=	${DEFAULT_DISTFILES} Daemon.png Daemon.README
DISTFILES+=	NetBSD-flag-1.0.png
SITES.Daemon.png=	${MASTER_SITE_LOCAL}
SITES.Daemon.README=	${MASTER_SITE_LOCAL}
SITES.NetBSD-flag-1.0.png=	${MASTER_SITE_LOCAL}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

USE_TOOLS+=		mkfontdir bdftopcf

FONTS_DIRS.x11+=	${PREFIX}/share/kde/fonts/override
REQD_DIRS+=		${PREFIX}/share/kde/fonts
REQD_DIRS+=		${PREFIX}/share/kde/fonts/override

RCD_SCRIPTS=		kdm

CONF_FILES=		${PREFIX}/share/kde/config/kdm/kdmrc \
			${PKG_SYSCONFDIR}/kdm/kdmrc
OWN_DIRS=		${PKG_SYSCONFDIR}/kdm

CONF_FILES+=		${PREFIX}/share/examples/kdebase-workspace4/ksysguarddrc \
			${PKG_SYSCONFDIR}/ksysguarddrc
CONF_FILES+=		${PREFIX}/share/examples/kdebase-workspace4/systemsettingsrc \
			${PKG_SYSCONFDIR}/systemsettingsrc

REPLACE_PERL+= \
	kcontrol/keys/convertShortcuts.pl \
	kwin/data/kwin3_plugin.pl \
	kwin/data/pluginlibFix.pl

PY_PATCHPLIST=	yes

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

SUBST_CLASSES+=		paths qtpath
SUBST_FILES.paths=	kcontrol/kdm/main.cpp
SUBST_SED.paths=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

SUBST_FILES.qtpath=	startkde.cmake
SUBST_SED.qtpath=	-e 's,/usr/pkg/qt4,${QTDIR},g'
SUBST_STAGE.qtpath=	post-patch

ICONDIR=		share/icons

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	rt
.else
RT_LIB_SCHED=	# empty
.endif
CMAKE_ARGS+=	-DRT_LIB_SCHED=${RT_LIB_SCHED}

post-install:
	${INSTALL_DATA} ${DISTDIR}/NetBSD-flag-1.0.png \
		${DESTDIR}${PREFIX}/${ICONDIR}/NetBSD-flag.png
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${DESTDIR}${PREFIX}/${ICONDIR}
	${INSTALL_DATA} ${DISTDIR}/Daemon.README \
		${DESTDIR}${PREFIX}/share/doc/kde/HTML/en/kdm
.if ${OPSYS} == "NetBSD"
	@# NetBSD Advertisement O:-)
	cd ${DESTDIR}${PREFIX}/share/kde/config/kdm;			\
	${SED} -e 's|^\(LogoPixmap\)=.*|\1=${PREFIX}/${ICONDIR}/NetBSD-flag.png|' \
                kdmrc > ${WRKDIR}/kdmrc.ad;				\
	${CP} -f ${WRKDIR}/kdmrc.ad kdmrc
.endif

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../wip/kde4/kde4.mk"

PYTHON_VERSIONS_ACCEPTED= 25 # because kdebindings4-python
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
# not yet - causes kdm logins to fail, presumably because
#  I don't know how consolekit works
#.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../wip/kdebindings4-python/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
