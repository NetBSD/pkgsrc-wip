# $NetBSD: Makefile,v 1.4 2004/01/22 22:59:00 rillig Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation

USE_GMAKE=	yes
USE_NCURSES=	yes

BUILD_DEPENDS+=	ncurses>=5.3:../../devel/ncurses

.include	"../../devel/ncurses/buildlink2.mk"
.include	"../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
BUILD_MAKE_FLAGS+=	LIBS="-L${LOCALBASE}/lib -lncurses -lnsl -lsocket -lresolv"
.endif
