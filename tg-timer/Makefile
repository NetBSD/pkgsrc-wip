# $NetBSD$

CHECKOUT_DATE=		20230707
PKGNAME=		tg-timer-${CHECKOUT_DATE}
CATEGORIES=		audio

MAINTAINER=		stix@stix.id.au
HOMEPAGE=		https://github.com/vacaboja/tg
COMMENT=		Open source Time Grapher for timing mechanical watches
LICENSE=		gnu-gpl-v2
DISTNAME=		tg-${CHECKOUT_DATE}
MASTER_SITES=		${MASTER_SITE_GITHUB:=vacaboja/}
GITHUB_TAG=		e35241d0c7e3252f843ef869c882bc9c45c82435
GITHUB_PROJECT=		tg
WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

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
.include "../../mk/bsd.pkg.mk"
