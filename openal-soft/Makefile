# $NetBSD: Makefile,v 1.4 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=	openal-soft-1.5.304
CATEGORIES=	audio
MASTER_SITES=	http://connect.creativelabs.com/openal/Downloads/ \
		http://kcat.strangesoft.net/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kcat.strangesoft.net/
COMMENT=	Alternative OpenAL implementation

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CMAKE_ARGS+=	-DALSA=OFF
.endif

CMAKE_ARGS+=	-DDSOUND=OFF
CMAKE_ARGS+=	-DWINMM=OFF

.include "../../mk/oss.buildlink3.mk"

.if !empty(BUILTIN_LIB_FOUND.ossaudio:M[Yy][Ee][Ss])
CMAKE_ARGS+=	-DEXTRA_LIBS=${LIBOSSAUDIO:Q}
.endif

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

SUBST_CLASSES+=			fix-oss
SUBST_STAGE.fix-oss=		pre-configure
SUBST_MESSAGE.fix-oss=		Fixing OSS device references.
SUBST_FILES.fix-oss=		Alc/oss.c
SUBST_SED.fix-oss=		-e 's,/dev/dsp,${DEVOSSSOUND},'

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
