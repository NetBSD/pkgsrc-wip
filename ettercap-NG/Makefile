# $NetBSD: Makefile,v 1.5 2004/12/23 00:22:14 adrian_p Exp $

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
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--disable-gtk

USE_BUILTIN.libpcap=	no
USE_BUILTIN.ncurses=	no

CONF_FILES=	${PREFIX}/share/examples/ettercap-NG/etter.conf \
		${PKG_SYSCONFDIR}/etter.conf

PKG_OPTIONS_VAR=        PKG_OPTIONS.ettercap-NG
PKG_SUPPORTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.	include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk
.endif

# Bad hack as I think there's a bug floating round the place
# with INSTALL_UNSTRIPPED=yes being ignored in cetain cases.
.if ${OPSYS} == "Darwin"
_STRIPFLAG_CC=		
_STRIPFLAG_INSTALL=	
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ettercap-NG
	${INSTALL_DATA} ${WRKSRC}/share/etter.conf \
		${PREFIX}/share/examples/ettercap-NG

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
