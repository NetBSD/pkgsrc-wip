# $NetBSD$

DISTNAME=	vamp-plugin-sdk-2.6
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/1520/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vamp-plugins.org/
COMMENT=	The Vamp audio analysis plugin system
LICENSE=	modified-bsd # mit with rider

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
