# $NetBSD: Makefile,v 1.3 2004/07/10 17:47:51 poppnk Exp $
#

DISTNAME=		xinetd-2.3.13
CATEGORIES=		wip
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

RCD_SCRIPTS=		xinetd
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE=\\\"\"${PREFIX}/etc/xinetd.conf\\\"\"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xinetd/
	${INSTALL_DATA} ${WRKSRC}/contrib/xinetd.conf \
		${PREFIX}/share/examples/xinetd/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xinetd/xinetd.d/
	${INSTALL_DATA} ${WRKSRC}/contrib/xinetd.d/* \
		${PREFIX}/share/examples/xinetd/xinetd.d/

.include "../../mk/bsd.pkg.mk"
