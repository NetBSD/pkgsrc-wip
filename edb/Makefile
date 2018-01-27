# $NetBSD: Makefile,v 1.3 2012/09/28 22:07:30 asau Exp $
#

DISTNAME=	edb-1.0.5.042
CATEGORIES=	databases
MASTER_SITES=	http://download.enlightenment.org/snaphots/2008-05-19/
MASTER_SITES+=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	Enlightenment Database Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

#USE_NCURSES=	yes # putwin # XXX Did other versions of NetBSD not have this?

CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-cxx

PKG_CFLAGS=		# defined
PKGCONFIG_OVERRIDE+=	edb.pc.in

CHECK_BUILTIN.db1:=	yes
.include "../../mk/db1.builtin.mk"
CHECK_BUILTIN.db1:=	no

.if !empty(USE_BUILTIN.db1:M[Yy][Ee][Ss])
USE_BDB185=		yes
.else
BDB_ACCEPTED=		db2
.endif

.if defined(PKG_DEVELOPER)
CPPFLAGS+=	-Wall
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
