# $NetBSD: Makefile,v 1.7 2009/02/09 20:01:16 othyro Exp $
#

DISTNAME=		ccrtp-1.7.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wiki.gnutelephony.org/
COMMENT=		RTP and RTSP protocol implementation using GNU CommonCpp

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES+=		c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
GNU_CONFIGURE=		yes
INFO_FILES=		yes
PKG_DESTDIR_SUPPORT=	destdir

.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
