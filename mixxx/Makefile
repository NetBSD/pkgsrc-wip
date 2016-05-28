# $NetBSD: Makefile,v 1.19 2013/04/13 07:58:29 ghen Exp $

DISTNAME=		mixxx-1.4.2
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mixxx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mixxx.sourceforge.net/
COMMENT=		Digital DJ tool

# needs pselect(2). if you know a workaround, please let me know.
NOT_FOR_PLATFORM=	NetBSD-[0-2]*-* FreeBSD-[0-4]*-* OpenBSD-*-* DragonFly-*-*


WRKSRC=			${WRKDIR}/${DISTNAME}/src

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE:Q}
CONFIGURE_ARGS+=	--dependency-dir=${LOCALBASE}/bin\;${LOCALBASE}/lib\;${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-jack

USE_LANGUAGES=		c++
USE_TOOLS+=		bash pkg-config
USE_LIBTOOL+=		yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	configure

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
