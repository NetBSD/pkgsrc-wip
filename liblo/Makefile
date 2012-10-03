# $NetBSD: Makefile,v 1.6 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=	liblo-0.24
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liblo/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://liblo.sourceforge.net/
COMMENT=	Lightweight Open Sound Control implementation

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CFLAGS+=		${PTHREAD_CFLAGS}
PKGCONFIG_OVERRIDE+=	liblo.pc.in
PTHREAD_OPTS+=		require
RESOLV_AUTO_VARS=	yes	# gethostbyname and friends

SUBST_CLASSES=		conf
SUBST_FILES.conf=	configure Makefile.in src/Makefile.in liblo.pc.in
SUBST_MESSAGE.conf=	Performing build-time configuration substitutions.
SUBST_SED.conf=		-e 's,-lpthread,$${PTHREAD_LDFLAGS} $${PTHREAD_LIBS},'
SUBST_STAGE.conf=	post-patch
SUBST_VARS.conf=	PTHREAD_CFLAGS PTHREAD_LDFLAGS PTHREAD_LIBS

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
