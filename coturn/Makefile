# $NetBSD$

DISTNAME=	coturn-4.5.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=coturn/}
GITHUB_PROJECT=	coturn

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/coturn/coturn
COMMENT=	The TURN Server is a VoIP media traffic NAT traversal server
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

HAS_CONFIGURE=	yes

# Pass cflags/libs
CONFIGURE_ENV+=		PTHREAD_LIBS=-pthread TURN_DISABLE_RPATH=1
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

# Configure installation paths.
# \todo Why is this not setting PREFIX?
CONFIGURE_ENV+=		BINDIR=${PREFIX}/bin
CONFIGURE_ENV+=		LIBDIR=${PREFIX}/lib
CONFIGURE_ENV+=		MANPREFIX=${PREFIX}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		INCLUDEDIR=${PREFIX}/include
CONFIGURE_ENV+=		LOCALSTATEDIR=${PREFIX}/var/turnserver
CONFIGURE_ENV+=		DOCSDIR=${PREFIX}/share/doc/coturn
CONFIGURE_ENV+=		EXAMPLESDIR=${PREFIX}/share/examples/coturn
CONFIGURE_ENV+=		TURNDBDIR=${VARBASE}/turnserver
CONFIGURE_ENV+=		TURNINCLUDEDIR=${PREFIX}/include/turn

# \todo Does the package really not make these?
INSTALLATION_DIRS+=	bin lib ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PREFIX}/var/turnserver
INSTALLATION_DIRS+=	share/doc/coturn share/examples/coturn

#CONF_FILES+=		${PREFIX}/etc/turnserver.conf.default
#RCD_SCRIPTS=		turnserver

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
