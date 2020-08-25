# $NetBSD$

DISTNAME=	crispy-doom-5.9.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fabiangreffrath/}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/fabiangreffrath/crispy-doom/
COMMENT=	Limit-removing enhanced-resolution Doom source port
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c99
USE_TOOLS+=		autoconf automake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_prog_HAVE_PYTHON=python${PYVERSSUFFIX}
PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON=		man/docgen
REPLACE_PYTHON+=	man/simplecpp

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS+=	share/doc/crispy-doom
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	${PKGMANDIR}/man4

# Add DOOMWADDIR to search path
SUBST_CLASSES+=		waddir
SUBST_STAGE.waddir=	pre-configure
SUBST_MESSAGE.waddir=	Preparing d_iwad.c file ...
SUBST_FILES.waddir=	src/d_iwad.c
SUBST_SED.waddir=	-e 's,PKGSRC_PREFIX,"${PREFIX}",'
SUBST_SED.waddir+=	-e 's,PKGSRC_DOOMWADDIR,"/${DOOMWADDIR}",'

# Man pages with documentation of file formats should go to section 4 on
# SysV based systems. IRIX and OSF/1 are treated with BSD style by intent.
PLIST_VARS+=	bsd sysv
.if ${OPSYS} == "AIX" || ${OPSYS} == "HPUX" || ${OPSYS} == "SunOS"
PLIST.sysv=	yes
.else
PLIST.bsd=	yes
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fi
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/crispy-doom/INSTALL.pkgsrc
	${INSTALL_DATA} ${WRKSRC}/pkg/osx/Resources/app.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/crispy-doom.png
	${MV} ${DESTDIR}${PREFIX}/share/applications/io.github.fabiangreffrath.Doom.desktop \
		${DESTDIR}${PREFIX}/share/applications/crispy-doom.desktop
	${MV} ${DESTDIR}${PREFIX}/share/applications/io.github.fabiangreffrath.Heretic.desktop \
		${DESTDIR}${PREFIX}/share/applications/crispy-heretic.desktop
	${MV} ${DESTDIR}${PREFIX}/share/applications/io.github.fabiangreffrath.Setup.desktop \
		${DESTDIR}${PREFIX}/share/applications/crispy-setup.desktop
	${MV} ${DESTDIR}${PREFIX}/share/applications/screensavers/io.github.fabiangreffrath.Doom_Screensaver.desktop \
		${DESTDIR}${PREFIX}/share/applications/screensavers/crispy-doom_Screensaver.desktop
	${MV} ${DESTDIR}${PREFIX}/share/metainfo/io.github.fabiangreffrath.Doom.metainfo.xml \
		${DESTDIR}${PREFIX}/share/metainfo/crispy-doom.metainfo.xml
	${MV} ${DESTDIR}${PREFIX}/share/metainfo/io.github.fabiangreffrath.Heretic.metainfo.xml \
		${DESTDIR}${PREFIX}/share/metainfo/crispy-heretic.metainfo.xml
.if defined(PLIST.sysv)
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/crispy-doom.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/crispy-doom.cfg.4
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/crispy-heretic.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/crispy-heretic.cfg.4
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/default.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/default.cfg.4
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/heretic.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/heretic.cfg.4
.endif

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
