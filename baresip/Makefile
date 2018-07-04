# $NetBSD: Makefile,v 1.2 2014/09/05 08:06:00 thomasklausner Exp $

DISTNAME=	baresip-0.5.10
CATEGORIES=	net audio
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.creytiv.com/baresip.html
COMMENT=	SIP User-Agent with audio and video support
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
NO_CONFIGURE=	yes

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	post-patch

INSTALLATION_DIRS=	share/examples/baresip

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/examples/accounts ${DESTDIR}${PREFIX}/share/examples/baresip
	${INSTALL_DATA} ${WRKSRC}/docs/examples/config ${DESTDIR}${PREFIX}/share/examples/baresip
	${INSTALL_DATA} ${WRKSRC}/docs/examples/contacts ${DESTDIR}${PREFIX}/share/examples/baresip

CFLAGS+=	-DHAVE_GETOPT=1 -DHAVE_UNISTD_H=1
CFLAGS+=	${BUILDLINK_CFLAGS.pthread}
CFLAGS+=	${BUILDLINK_LIBS.pthread}
CFLAGS+=	${BUILDLINK_LDFLAGS.pthread}
CFLAGS+=	-D__ssize_t_defined

LFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libre}/lib

MAKE_FLAGS+=	HAVE_PTHREAD=yes
MAKE_FLAGS+=	MOD_AUTODETECT=
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	SYSROOT=${BUILDLINK_PREFIX.libre}

MAKE_FLAGS+=	USE_CONS=yes
MAKE_FLAGS+=	USE_G711=yes
MAKE_FLAGS+=	USE_G722=yes
MAKE_FLAGS+=	USE_G722_1=
MAKE_FLAGS+=	USE_G726=yes
MAKE_FLAGS+=	USE_GSM=yes
MAKE_FLAGS+=	USE_L16=yes
MAKE_FLAGS+=	USE_PLC=yes
MAKE_FLAGS+=	USE_SRTP=yes
MAKE_FLAGS+=	USE_STDIO=yes

.include "options.mk"

MAKE_FLAGS+=	LFLAGS="${LFLAGS}"

.include "../../audio/gsm/buildlink3.mk"
.include "../../comms/spandsp/buildlink3.mk"
.include "../../wip/libre/buildlink3.mk"
.include "../../wip/librem/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
