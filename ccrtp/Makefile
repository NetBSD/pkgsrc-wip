# $NetBSD: Makefile,v 1.16 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		ccrtp-2.0.3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/ccrtp/
COMMENT=		RTP and RTSP protocol implementation using GNU CommonCpp
LICENSE=		gnu-gpl-v2

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
