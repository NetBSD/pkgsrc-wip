# $NetBSD: Makefile,v 1.1.1.1 2006/02/04 11:39:27 thomasklausner Exp $
#

DISTNAME=		tcpxtract-1.0.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcpxtract/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tcpxtract.sourceforge.net/
COMMENT=		Extract files from network traffic based on file signatures

GNU_CONFIGURE=		yes
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE="\"${PKG_SYSCONFDIR}/tcpxtract.conf\""
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/share/examples/tcpxtract

CONF_FILES+=		${PREFIX}/share/examples/tcpxtract.conf ${PKG_SYSCONFDIR}/tcpxtract.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
