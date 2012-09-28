# $NetBSD: Makefile,v 1.1 2012/09/28 18:50:22 othyro Exp $
#

DISTNAME=	djplay-0.5.0
CATEGORIES=	audio net
MASTER_SITES=	http://sourceforge.net/projects/djplay/files/djplay/0.5.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/djplay/files/djplay/0.5.0/
COMMENT=	High class live DJing application
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		bpmcounter-[0-9]*:../../wip/bpmcounter

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake pkg-config
CONFIGURE_ARGS+=	--with-SoundTouchincludes=${BUILDLINK_PREFIX.libSoundTouch}/include/soundtouch/

SUBST_CLASSES+=		pixmaps
SUBST_STAGE.pixmaps=	pre-configure
SUBST_MESSAGE.pixmaps=	Fixing pixmaps path.
SUBST_FILES.pixmaps=	Makefile.am Makefile.in
SUBST_SED.pixmaps=	-e 's|/djplay|/pixmaps|1'

SUBST_CLASSES+=		qmake
SUBST_STAGE.qmake=	pre-configure
SUBST_MESSAGE.qmake=	Fixing qmake path.
SUBST_FILES.qmake=	plugins/Makefile.in
SUBST_SED.qmake=	-e "s|qmake|${QTDIR}/bin/qmake|1"

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../wip/libSoundTouch/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../wip/libdjconsole/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
