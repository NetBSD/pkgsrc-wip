# $NetBSD: Makefile,v 1.2 2006/05/19 16:51:39 ykomatsu Exp $
#

DISTNAME=		tcpxtract-1.0.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcpxtract/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcpxtract.sourceforge.net/
COMMENT=		Extract files from network traffic based on file signatures

GNU_CONFIGURE=		yes
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE="\"${PKG_SYSCONFDIR}/tcpxtract.conf\""
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/share/examples/tcpxtract

CONF_FILES+=		${PREFIX}/share/examples/tcpxtract.conf ${PKG_SYSCONFDIR}/tcpxtract.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
