# $NetBSD$

PKGNAME=		tg-timer-0
CATEGORIES=		audio

MAINTAINER=		stix@stix.id.au
HOMEPAGE=		https://github.com/vacaboja/tg
COMMENT=		Open source Time Grapher for timing mechanical watches
LICENSE=		gnu-gpl-v2
GIT_REPO=		https://github.com/vacaboja/tg

ICON_THEMES=		yes
USE_LANGUAGES=		c
GNU_CONFIGURE=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake gmake pkg-config

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../audio/portaudio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
