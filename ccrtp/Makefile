# $NetBSD: Makefile,v 1.13 2012/01/03 19:56:35 othyro Exp $
#

DISTNAME=		ccrtp-2.0.2
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/ccrtp/
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
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
