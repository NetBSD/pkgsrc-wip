# $NetBSD: Makefile,v 1.18 2013/04/15 01:10:43 othyro Exp $
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/ucommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
