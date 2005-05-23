# $NetBSD: Makefile,v 1.8 2005/05/23 09:41:34 rillig Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation

USE_TOOLS+=	gmake

MAKE_ENV+=	LIBS=${LIBS:Q}
LIBS.SunOS+=	-lnsl -lsocket -lresolv

.include	"../../mk/bsd.pkg.mk"
