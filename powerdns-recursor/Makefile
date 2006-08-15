# $NetBSD: Makefile,v 1.1.1.1 2006/08/15 13:15:00 ondratu Exp $
#

DISTNAME=		pdns-recursor-3.1.2
CATEGORIES=		net
MASTER_SITES=		http://downloads.powerdns.com/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://www.powerdns.com/
COMMENT=		PowerDNS resolver/recursing nameserver

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

RCD_SCRIPTS+=		pdns_recursor

EGDIR=			${PREFIX}/share/examples/pdns-recursor
MAKE_ENV+=		EGDIR=${EGDIR}

CONF_FILES+=		${EGDIR}/recursor.conf-dist ${PKG_SYSCONFDIR}/recursor.conf

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
