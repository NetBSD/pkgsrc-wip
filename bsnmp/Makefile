# $NetBSD: Makefile,v 1.2 2012/09/24 17:14:42 asau Exp $

DISTNAME=	bsnmp-1.12
CATEGORIES=	net
MASTER_SITES=	http://people.freebsd.org/~harti/bsnmp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.freebsd.org/~harti/bsnmp/
COMMENT=	Minimal SNMP daemon
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-libbegemot=${PREFIX}/lib

.include "../../devel/libbegemot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
