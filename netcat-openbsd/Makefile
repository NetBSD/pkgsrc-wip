# $NetBSD: Makefile,v 1.2 2013/12/07 21:16:43 genolopolis Exp $
#

PKGNAME=	netcat-openbsd-1
CATEGORIES=	net
DISTNAME=	msporleder-netcat-openbsd-eb56dd1
MASTER_SITES=	-https://codeload.github.com/msporleder/netcat-openbsd/legacy.tar.gz/eb56dd1
FETCH_USING=	curl
#FETCH_OUTPUT_ARGS=	${DISTNAME}
LICENSE=		modified-bsd

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openbsd.org/
COMMENT=	Arbitrary TCP and UDP connections and listens
CONFLICTS=	netcat-[0-9]*

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
