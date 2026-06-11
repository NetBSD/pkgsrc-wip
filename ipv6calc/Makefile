# $NetBSD: Makefile,v 1.39 2020/01/26 17:31:50 rillig Exp $
#

DISTNAME=	ipv6calc-4.4.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/
MASTER_SITES+=	ftp://sunsite.icm.edu.pl/pub/Linux/ipv6/bipv6/ipv6calc/

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_TOOLS+=	bash

MAKE_FLAGS+=	CFLAGS="${CFLAGS} -Wno-error=char-subscripts -Wno-char-subscripts"

REPLACE_PERL+= \
	tools/ipv6calc-create-registry-list-ipv4.pl \
	tools/ipv6calc-create-registry-list-ipv6.pl

REPLACE_BASH+= \
	ipv6calcweb/create_ipv6calcweb-cgi.sh \
	tools/DBIP-update.sh.in \
	tools/GeoIP-update.sh.in \
	tools/IP2Location-update.sh.in \
	tools/ipv6calc-create-update-ipset.sh \
	tools/ipv6calc-db-update-support.sh \
	tools/ipv6calc-db-update.sh.in

.include "../../mk/bsd.pkg.mk"
