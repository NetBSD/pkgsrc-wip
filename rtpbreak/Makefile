# $NetBSD: Makefile,v 1.1.1.1 2009/07/15 22:42:15 prudhvikrishna Exp $
#

DISTNAME=	rtpbreak-1.3a
CATEGORIES=	net
MASTER_SITES=	http://xenion.antifork.org/rtpbreak/
EXTRACT_SUFX=	.tgz

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://xenion.antifork.org/rtpbreak/
COMMENT=	Detects, reconstructs and analyzes any RTP session

DEPENDS+=	libnet11>=1.1.2.1:../../devel/libnet11

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rtpbreak ${PREFIX}/bin/rtpbreak

.include "../../devel/libnet11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
