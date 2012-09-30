# $NetBSD: Makefile,v 1.10 2012/09/30 05:44:15 asau Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=	gmake

MAKE_ENV+=	LIBS=${LIBS:M*:Q}
LIBS.SunOS+=	-lnsl -lsocket -lresolv

.include	"../../mk/bsd.pkg.mk"
