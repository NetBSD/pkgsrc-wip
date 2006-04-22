# $NetBSD: Makefile,v 1.6 2006/04/22 10:48:37 rillig Exp $
#

DISTNAME=		mpcsv7-src-1.15t
PKGNAME=		musepack-1.15t
CATEGORIES=		audio
MASTER_SITES=		http://www.saunalahti.fi/grimmel/musepack.net-files/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		MPEG-Plus and MusePack decoder

WRKSRC=			${WRKDIR}/sv7
MAKEFILE=		Makefile.bsd
MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=		PREFIX=${PREFIX:Q}


SUBST_CLASSES+=		osconf
SUBST_MESSAGE.osconf=	Configuring os-specific build-time definitions.
SUBST_STAGE.osconf=	post-patch
SUBST_FILES.osconf=	mpp.h
SUBST_SED.osconf=	-e 's,\#define USE_ESD_AUDIO,// &,g' \
			-e 's,\#define USE_IRIX_AUDIO,// &,g' \
			-e 's,\#define USE_WIN_AUDIO,// &,g' \
			-e 's,\#define USE_REALTIME,// &,g'

.include "../../mk/bsd.prefs.mk"

.if empty(MACHINE_PLATFORM:M*-*-i386)
SUBST_SED.osconf+=	-e 's,\#define USE_ASM,// &,g'
.else
BUILD_DEPENDS=		nasm>=0.98:../../devel/nasm
.endif

pre-patch:
	cd ${WRKSRC} && ${MV} install install.txt

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
