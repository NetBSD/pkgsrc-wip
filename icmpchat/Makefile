# $NetBSD: Makefile,v 1.5 2004/01/23 01:50:12 rillig Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation

USE_GMAKE=	yes
USE_NCURSES=	yes # The Solaris 8 curses misses some functions

BUILD_DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses

MAKE_ENV+=	LIBS="${LIBS}"
LIBS.SunOS+=	-lnsl -lsocket -lresolv

.include	"../../devel/ncurses/buildlink2.mk"
.include	"../../mk/bsd.pkg.mk"
