# $NetBSD: Makefile,v 1.5 2014/08/11 23:10:14 thomasklausner Exp $

DISTNAME=	pjproject-2.1
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.pjsip.org/release/2.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	https://www.pjsip.org/
COMMENT=	FOSS multimedia communication library written in C language
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pjproject-2.1.0
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libpjproject.pc.in
PKGCONFIG_OVERRIDE+=	third_party/portaudio/portaudio-2.0.pc.in

.include "options.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}

SUBST_CLASSES+=		cross
SUBST_FILES.cross=	build/cc-auto.mak
SUBST_MESSAGE.cross=	Fixing AR and RANLIB.
SUBST_SED.cross=	-e 's/ccar/ar/1'
SUBST_SED.cross+=	-e 's/ccranlib/ranlib/1'
SUBST_STAGE.cross=	post-configure

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
