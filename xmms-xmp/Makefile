# $NetBSD: Makefile,v 1.1.1.1 2006/09/30 17:04:55 thomaspfaff Exp $
#

DISTNAME=		xmp-2.0.5pre3
PKGNAME=		xmms-xmp-2.0.5pre3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		thomaspfaff@users.sourceforge.net
HOMEPAGE=		http://xmp.sourceforge.net/
COMMENT=		XMP input plugin for XMMS

WRKSRC=			${WRKDIR}/xmp-2.0.5-pre3
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--disable-alsa --disable-oss --disable-esd \
			--disable-arts --disable-nas

do-install:
			${INSTALL_LIB} ${WRKSRC}/src/xmms/xmp-plugin.so \
			${PREFIX}/lib/xmms/Input

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
