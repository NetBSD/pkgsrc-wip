# $NetBSD$

DISTNAME=	coturn-4.5.0.6
CATEGORIES=	net
GITHUB_PROJECT=	coturn
MASTER_SITES=	${MASTER_SITE_GITHUB:=coturn/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/coturn/coturn
COMMENT=	The TURN Server is a VoIP media traffic NAT traversal server
LICENSE=	citrix_ica-license

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ENV+=		PTHREAD_LIBS=-pthread TURN_DISABLE_RPATH=1
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"
CONFIGURE_ENV+=		LOCALSTATEDIR=/var
CONFIGURE_ENV+=		BINDIR=${PREFIX}/bin
CONFIGURE_ENV+=		LIBDIR=${PREFIX}/lib
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		MANPREFIX=${PREFIX}
CONFIGURE_ENV+=		DOCSDIR=${PREFIX}/share/doc
CONFIGURE_ENV+=		INCLUDEDIR=${PREFIX}/include
CONFIGURE_ENV+=		EXAMPLESDIR=${PREFIX}/share/examples
CONFIGURE_ENV+=		TURNDBDIR=${PREFIX}/share/turnserver
CONFIGURE_ENV+=		TURNINCLUDEDIR=${PREFIX}/include/turn

INSTALLATION_DIRS+=	bin include lib ${PKGMANDIR}/man1 share/doc share/examples/etc share/examples/scripts share/turnserver
#CONF_FILES+=		${PREFIX}/etc/turnserver.conf.default
#RCD_SCRIPTS=		turnserver

WRKSRC=		${WRKDIR}/${DISTNAME}
HAS_CONFIGURE=	yes

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
