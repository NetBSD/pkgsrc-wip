# $NetBSD: Makefile,v 1.4 2009/03/21 15:25:44 jihbed Exp $
#

DISTNAME=		tcpxtract-1.0.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcpxtract/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcpxtract.sourceforge.net/
COMMENT=		Extract files from network traffic based on file signatures

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE="\"${PKG_SYSCONFDIR}/tcpxtract.conf\""
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/share/examples/tcpxtract

CONF_FILES+=		${PREFIX}/share/examples/tcpxtract/tcpxtract.conf ${PKG_SYSCONFDIR}/tcpxtract.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
