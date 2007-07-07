# $NetBSD: Makefile,v 1.3 2007/07/07 04:14:51 othyro Exp $
#

DISTNAME=		ccrtp-1.3.5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnutelephony/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wiki.gnutelephony.org/
COMMENT=		RTP and RTSP protocol implementation using GNU CommonCpp

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
