# $NetBSD: Makefile,v 1.1.1.1 2004/10/07 19:06:50 adrian_p Exp $

DISTNAME=	ettercap-NG-0.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ettercap/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://ettercap.sourceforge.net/
COMMENT=	Multipurpose sniffer/interceptor/logger for switched LAN

CONFLICTS=	ettercap-0*

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
PTHREAD_OPTS+=		require
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--disable-gtk

USE_BUILTIN.libpcap=	no
USE_BUILTIN.ncurses=	no

CONF_FILES=	${WRKSRC}/share/etter.conf ${PKG_SYSCONFDIR}/etter.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-plugins
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
