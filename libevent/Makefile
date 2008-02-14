# $NetBSD: Makefile,v 1.1.1.1 2008/02/14 15:23:15 athaba Exp $
#

DISTNAME=	libevent-1.4.1-beta
PKGNAME=	${DISTNAME:S/-alpha//}
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://monkey.org/~provos/
COMMENT=	Asynchronous event notification library (beta)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	verify
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	libevent-[0-9]*

LIBS.SunOS+=	-lnsl -lresolv

.include "../../mk/bsd.pkg.mk"
.include "../../mk/bsd.prefs.mk"

# Solaris and HPUX don't have u_intX_t types in <inttypes.h>.
.if ${OPSYS} == "SunOS" || ${OPSYS} == "HPUX"
CFLAGS+=	-Du_int8_t=uint8_t
CFLAGS+=	-Du_int16_t=uint16_t
CFLAGS+=	-Du_int32_t=uint32_t

SUBST_CLASSES+=		inttypes
SUBST_STAGE.inttypes=	post-patch
SUBST_FILES.inttypes=	event.h
SUBST_SED.inttypes=	-e "s,<stdint\\.h>,<inttypes.h>,g"
SUBST_SED.inttypes+=	-e "s,u_int8_t,uint8_t,g"
SUBST_SED.inttypes+=	-e "s,u_int16_t,uint16_t,g"
SUBST_SED.inttypes+=	-e "s,u_int32_t,uint32_t,g"
.endif
