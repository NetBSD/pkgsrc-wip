# $NetBSD: Makefile,v 1.1.1.1 2004/08/10 13:49:40 imilh Exp $

DISTNAME=		libpcap-0.8.3
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		lex yacc

.include "../../mk/bsd.prefs.mk"

# those 2 come from 0.7.2 pcap pkgsrc :

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
.  if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
