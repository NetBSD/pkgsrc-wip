# $NetBSD: Makefile,v 1.1.1.1 2006/12/28 17:14:41 jakllsch Exp $
#

DISTNAME=	wide-dhcpv6-20061016
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wide-dhcpv6/}

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://wide-dhcpv6.sourceforge.net/
COMMENT=	DHCPv6 client and server

USE_LANGUAGES+=		c
GNU_CONFIGURE=		yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=        Fixing absolute paths.
SUBST_FILES.fix-paths=		dhcp6*8 dhcp6*5
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
