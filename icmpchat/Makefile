# $NetBSD: Makefile,v 1.9 2005/11/28 00:27:25 rillig Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation

USE_TOOLS+=	gmake

MAKE_ENV+=	LIBS=${LIBS:M*:Q}
LIBS.SunOS+=	-lnsl -lsocket -lresolv

.include	"../../mk/bsd.pkg.mk"
