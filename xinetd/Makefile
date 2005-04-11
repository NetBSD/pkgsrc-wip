# $NetBSD: Makefile,v 1.10 2005/04/11 21:16:17 tvierling Exp $
#

DISTNAME=		xinetd-2.3.13
CATEGORIES=		sysutils
MASTER_SITES=		http://www.xinetd.org/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.xinetd.org/
COMMENT=		Secure replacement for inetd

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
BUILD_TARGET=		build
CONFIGURE_ARGS+=	--with-loadavg

.include "../../mk/bsd.prefs.mk"

# OPTIONS
BUILD_DEFS=	XINETD_USE_TCPWRAPPER
XINETD_USE_TCPWRAPPER?=NO
.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}/lib
.endif

RCD_SCRIPTS=		xinetd
CPPFLAGS+=	-DDEFAULT_CONFIG_FILE=\\\"\"${PKG_SYSCONFDIR}/etc/xinetd.conf\\\"\"

USE_PERL5=YES
REPLACE_PERL+=	${WRKSRC}/xinetd/xconv.pl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xinetd/
	${INSTALL_DATA} ${WRKSRC}/contrib/xinetd.conf \
		${PREFIX}/share/examples/xinetd/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xinetd/xinetd.d/
	${INSTALL_DATA} ${WRKSRC}/contrib/xinetd.d/* \
		${PREFIX}/share/examples/xinetd/xinetd.d/

.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
