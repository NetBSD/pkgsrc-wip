# $NetBSD: Makefile,v 1.6 2004/12/02 16:38:57 thomasklausner Exp $
#

DISTNAME=	cdpr-1.0.8
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdpr/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.monkeymental.com/
COMMENT=	Cisco Discovery Protocol Reporter

USE_BUILDLINK3=         yes
BUILD_TARGET=		cdpr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpr ${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
