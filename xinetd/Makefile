# $NetBSD: Makefile,v 1.5 2004/07/10 22:49:25 poppnk Exp $
#

DISTNAME=		xinetd-2.3.13
CATEGORIES=		wip sysutils
MASTER_SITES=		http://www.xinetd.org/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.xinetd.org/
COMMENT=		Secure replacement for inetd

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
ALL_TARGET=		build
CONFIGURE_ARGS+=	--with-loadavg

# OPTIONS
BUILD_DEFS=	XINETD_USE_TCPWRAPPER
XINETD_USE_TCPWRAPPER?=NO
.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}/lib
.endif

RCD_SCRIPTS=		xinetd
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE=\\\"\"${PREFIX}/etc/xinetd.conf\\\"\"

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
