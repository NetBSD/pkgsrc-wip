# $NetBSD: Makefile,v 1.1.1.1 2006/04/10 13:47:13 lkundrak Exp $

DISTNAME=		netrik-1.15.3
CATEGORIES=		www net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netrik/}

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://10.86.12.1/~lkundrak/src/
COMMENT=		Will be a really fancy text mode WWW browser

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_BUILTIN.ncurses=	no

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
