# $NetBSD: Makefile,v 1.1.1.1 2004/04/14 23:18:57 adrian_p Exp $

DISTNAME=	fping-2.4b2_to-ipv6
PKGNAME=	fping6-2.4b2
CATEGORIES=	net
MASTER_SITES=	http://unfix.org/projects/ipv6/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://unfix.org/projects/ipv6/
COMMENT=	Quickly ping many hosts w/o flooding the network (with IPv6)

BUILD_DEFS+=	USE_INET6
USE_BUILDLINK3=	YES
CONFLICTS+=	fping-[0-9]*

GNU_CONFIGURE=	YES

post-install:
	${CHMOD} 4555 ${PREFIX}/sbin/fping
	${CHMOD} 4555 ${PREFIX}/sbin/fping6

.include "../../mk/bsd.pkg.mk"
