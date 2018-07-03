# $NetBSD: Makefile,v 1.12 2015/09/06 10:17:35 leot1990 Exp $

DISTNAME=	mpv-0.10.0
CATEGORIES=	multimedia
MASTER_SITES=	-https://github.com/mpv-player/mpv/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mpv.io/
COMMENT=	Video player based on MPlayer and mplayer2 (git version)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
# ${WRKSRC}/bootstrap.py mentions needed version
BUILD_DEPENDS+=	waf>=1.8.4:../../devel/waf

GIT_REPOSITORIES=	mpv
GIT_REPO.mpv=		git://github.com/mpv-player/mpv.git
WRKSRC=			${WRKDIR}/mpv

PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-docutils

USE_TOOLS+=	perl pkg-config

MAKE_DIRS=		${PKG_SYSCONFDIR}/mpv
INSTALLATION_DIRS=	share/examples/mpv
CONF_FILES+=		share/examples/mpv/encoding-profiles.conf ${PKG_SYSCONFDIR}/mpv/encoding-profiles.conf

SUBST_CLASSES+=		audio
SUBST_SED.audio+=	-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_FILES.audio+=	stream/audio_in.c waftools/checks/custom.py wscript
SUBST_STAGE.audio=	pre-configure
SUBST_MESSAGE.audio=	Fixing path to audio device.

SUBST_CLASSES+=		docutils
SUBST_SED.docutils+=	-e "s,rst2man,rst2man-${PYVERSSUFFIX},"
SUBST_FILES.docutils+=	wscript
SUBST_STAGE.docutils=	pre-configure
SUBST_MESSAGE.docutils=	Fix docutils command names.

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} etc/mpv/encoding-profiles.conf share/examples/mpv

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif

.include "../../devel/waf/waf.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
