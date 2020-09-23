# $NetBSD$

DISTNAME=	crispy-doom-5.9.2
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
# GNU make is required for man page generation (broken with BSD make)
USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_prog_HAVE_PYTHON=python${PYVERSSUFFIX}
PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON=		man/docgen
REPLACE_PYTHON+=	man/simplecpp

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS+=	share/doc/crispy-doom
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

# Add DOOMWADDIR to search path
SUBST_CLASSES+=		waddir
SUBST_STAGE.waddir=	pre-configure
SUBST_MESSAGE.waddir=	Preparing d_iwad.c file ...
SUBST_FILES.waddir=	src/d_iwad.c
SUBST_SED.waddir=	-e 's,PKGSRC_PREFIX,"${PREFIX}",'
SUBST_SED.waddir+=	-e 's,PKGSRC_DOOMWADDIR,"/${DOOMWADDIR}",'

# Man pages with documentation of file formats (section 5 on BSD) should go
# go to section 4 on SysV based systems.
# Note: IRIX and OSF/1 are treated with BSD style by intent.
PLIST_VARS+=		bsd sysv
.if ${OPSYS} == "AIX" || ${OPSYS} == "HPUX" || ${OPSYS} == "SunOS"
PLIST.sysv=		yes

SUBST_CLASSES+=		manpages
SUBST_STAGE.manpages=	pre-configure
SUBST_MESSAGE.manpages=	Modify man pages for section 5 to use section 4 ...
SUBST_FILES.manpages=	man/default.cfg.template man/extra.cfg.template
SUBST_SED.manpages=	-e 's,5$$,4,'
SUBST_SED.manpages+=	-e 's,[(]5[)],(4),g'

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Modify Makefile template for man page generation ...
SUBST_FILES.makefile=	man/Makefile.am
SUBST_SED.makefile=	-e 's,[.]5,.4,g'
.else
PLIST.bsd=		yes
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fi
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

# Rename XDG files to the style of chocolate-doom
# Rename man pages so that they don't collide with chocolate-doom
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
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/default.cfg.4 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/crispy-default.cfg.4
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/heretic.cfg.4 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/crispy-heretic.cfg.4
.else
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/default.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/crispy-default.cfg.5
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/heretic.cfg.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/crispy-heretic.cfg.5
.endif

BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.2
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2+=		SDL2>=2.0.7
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
