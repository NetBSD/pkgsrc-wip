# $NetBSD: Makefile,v 1.2 2006/05/01 14:20:08 shattered Exp $

DISTNAME=		netrik-1.15.3
CATEGORIES=		www net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netrik/}

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://netrik.sourceforge.net/
COMMENT=		Will be a really fancy text mode WWW browser

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_BUILTIN.ncurses=	no

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
