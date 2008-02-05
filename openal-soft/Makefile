# $NetBSD: Makefile,v 1.1 2008/02/05 02:14:19 bsadewitz Exp $
#

DISTNAME=	openal-soft-1.2.218
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
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

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
