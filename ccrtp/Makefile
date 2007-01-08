# $NetBSD: Makefile,v 1.2 2007/01/08 01:05:26 shattered Exp $
#

DISTNAME=		ccrtp-1.3.5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnutelephony/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wiki.gnutelephony.org/
COMMENT=		RTP and RTSP protocol implementation using GNU CommonCpp

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
