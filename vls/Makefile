# $NetBSD: Makefile,v 1.1.1.1 2004/01/16 09:46:56 xtraeme Exp $
#

DISTNAME=		vls-0.5.5
CATEGORIES=		net
MASTER_SITES=		http://download.videolan.org/pub/videolan/vls/0.5.5/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Server

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-dvbpsi=${BUILDLINK_PREFIX.libdvbpsi}

EGDIR=			${PREFIX}/share/examples/vls
CONF_FILES=		${EGDIR}/vls.cfg ${PKG_SYSCONFDIR}/vls.cfg

.include "../../graphics/libdvbpsi/buildlink2.mk"
.include "../../misc/libdvdplay/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
