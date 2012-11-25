# $NetBSD: Makefile,v 1.11 2012/11/25 23:32:21 othyro Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=	gmake

MAKE_ENV+=	LIBS=${LIBS:M*:Q}
LIBS.SunOS+=	-lnsl -lsocket -lresolv

.include	"../../mk/bsd.pkg.mk"
