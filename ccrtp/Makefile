# $NetBSD: Makefile,v 1.11 2011/10/29 01:40:02 othyro Exp $
#

DISTNAME=		ccrtp-2.0.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wiki.gnutelephony.org/
COMMENT=		RTP and RTSP protocol implementation using GNU CommonCpp
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
INFO_FILES=		yes

.include "../../wip/ucommon/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
