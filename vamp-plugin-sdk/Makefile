# $NetBSD$

DISTNAME=	vamp-plugin-sdk-2.6
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/1520/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vamp-plugins.org/
COMMENT=	The Vamp audio analysis plugin system
LICENSE=	x11

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp.pc.in

pre-patch:
	${RUN} cp ${FILESDIR}/wscript ${WRKSRC}

.include "../../devel/waf/waf.mk"
# Missing --mandir
WAF_ARGS=
.include "../../math/fftw/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
