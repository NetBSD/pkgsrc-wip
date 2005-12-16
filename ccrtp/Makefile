# $NetBSD: Makefile,v 1.1.1.1 2005/12/16 10:14:26 poppnk Exp $
#

DISTNAME=		ccrtp-1.3.5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnutelephony/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://gnutelephony.sourceforge.net/
COMMENT=		RTP and RTSP protocol implementation using GNU CommonCpp

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
