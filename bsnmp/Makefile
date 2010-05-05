# $NetBSD: Makefile,v 1.1.1.1 2010/05/05 16:04:38 hfath Exp $

DISTNAME=	bsnmp-1.12
CATEGORIES=	net
MASTER_SITES=	http://people.freebsd.org/~harti/bsnmp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~harti/bsnmp/
COMMENT=	Minimal SNMP daemon
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-libbegemot=${PREFIX}/lib

.include "../../devel/libbegemot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
