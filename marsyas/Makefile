# $NetBSD: Makefile,v 1.5 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=	marsyas-0.2.16
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=marsyas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marsyas.sourceforge.net/
COMMENT=	Music Analysis, Retrieval and Synthesis for Audio Signals


GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--disable-midi

BROKEN_READLINE_DETECTION=	yes
CHECK_PORTABILITY_SKIP=		otherlibs/Qwt/admin/svn2package.sh
PTHREAD_OPTS=			require native

SUBST_CLASSES+=		pthread
SUBST_FILES.pthread=	configure
SUBST_MESSAGE.pthread=	adjusting pthread flags
SUBST_SED.pthread=	-e 's,-lpthread,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_STAGE.pthread=	pre-configure


CFLAGS+=	${PTHREAD_CFLAGS}

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} != "unknown"
CFLAGS+=	-D__${MACHINE_ENDIAN:tu}_ENDIAN__
.else
BROKEN=		Unknown endianness
.endif

.include "../../mk/bsd.prefs.mk"

MARSYAS_OPSYS_LINUX=	Linux FreeBSD NetBSD OpenBSD DragonFly

.if !empty(MARSYAS_OPSYS_LINUX:M${OPSYS})
CFLAGS+=	-DMARSYAS_LINUX
.endif


.include "options.mk"

post-extract:
	${RUN} ${FIND} ${WRKSRC} -path \*.svn\* -rm

.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
