# $NetBSD: Makefile,v 1.12 2012/12/04 19:15:26 othyro Exp $

DISTNAME=	icmpchat-0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpchat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icmpchat.sourceforge.net/
COMMENT=	Simple chat using ICMP and Rijndael-256 encryptation
LICENSE=	modified-bsd


USE_TOOLS+=	gmake

MAKE_ENV+=	LIBS=${LIBS:M*:Q}
LIBS.SunOS+=	-lnsl -lsocket -lresolv

.include	"../../mk/bsd.pkg.mk"
