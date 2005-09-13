# $NetBSD: Makefile,v 1.2 2005/09/13 06:17:58 ghen Exp $

DISTNAME=	mixxx-1.4.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mixxx/}

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://mixxx.sourceforge.net/
COMMENT=	Digital DJ tool

WRKSRC=		${WRKDIR}/${DISTNAME}/src

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--dependency-dir=${LOCALBASE}/bin\;${LOCALBASE}/lib\;${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-jack

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_FILES.bash=	configure
SUBST_SED.bash=		-e 's,%%LOCALBASE%%,${LOCALBASE},g'

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
