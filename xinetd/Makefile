# $NetBSD: Makefile,v 1.14 2012/10/07 20:11:09 asau Exp $
#

DISTNAME=		xinetd-2.3.13
CATEGORIES=		sysutils
MASTER_SITES=		http://www.xinetd.org/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.xinetd.org/
COMMENT=		Secure replacement for inetd

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		build
CONFIGURE_ARGS+=	--with-loadavg

.include "../../mk/bsd.prefs.mk"

# OPTIONS
BUILD_DEFS+=		XINETD_USE_TCPWRAPPER
XINETD_USE_TCPWRAPPER?=	NO
.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers:Q}/lib
.endif

RCD_SCRIPTS=		xinetd
# Some weird quoting in Makefile.in makes this necessary.
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE="\"${PKG_SYSCONFDIR:Q}/etc/xinetd.conf\""

USE_TOOLS+=		perl:run
REPLACE_PERL+=		xinetd/xconv.pl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/xinetd/
	${INSTALL_DATA} ${WRKSRC:Q}/contrib/xinetd.conf \
		${PREFIX:Q}/share/examples/xinetd/
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/xinetd/xinetd.d/
	${INSTALL_DATA} ${WRKSRC:Q}/contrib/xinetd.d/* \
		${PREFIX:Q}/share/examples/xinetd/xinetd.d/

.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
