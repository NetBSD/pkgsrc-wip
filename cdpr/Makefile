# $NetBSD: Makefile,v 1.7 2005/04/11 21:10:25 tvierling Exp $
#

DISTNAME=	cdpr-1.0.8
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdpr/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.monkeymental.com/
COMMENT=	Cisco Discovery Protocol Reporter

BUILD_TARGET=		cdpr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpr ${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
