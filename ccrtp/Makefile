# $NetBSD: Makefile,v 1.17 2013/03/26 10:45:30 othyro Exp $
#

DISTNAME=	ccrtp-2.0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ccrtp/
COMMENT=	RTP and RTSP protocol implementation using GNU CommonCpp
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libccrtp1.pc.in
INFO_FILES=		yes

.include "options.mk"

.include "../../wip/ucommon/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
