# $NetBSD: Makefile,v 1.1.1.1 2006/01/17 07:51:18 rillig Exp $
#

DISTNAME=		mc-4.1.40-pre9
PKGNAME=		mc-mp-4.1.39.99.9
CATEGORIES=		sysutils
MASTER_SITES=		http://mc.linuxinside.com/Releases/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://mc.linuxinside.com/cgi-bin/dir.cgi
COMMENT=		Midnight Commander clone

CONFLICTS+=		mc-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CPPFLAGS.NetBSD+=	-DNO_INFOMOUNT

.include "../../mk/bsd.pkg.mk"
