# $NetBSD: Makefile,v 1.3 2004/02/06 23:03:57 thomasklausner Exp $
#

DISTNAME=		vls-0.5.5
CATEGORIES=		net
MASTER_SITES=		http://download.videolan.org/pub/videolan/vls/0.5.5/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLAN Server

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-dvbpsi=${BUILDLINK_PREFIX.libdvbpsi}

EGDIR=			${PREFIX}/share/examples/vls
CONF_FILES=		${EGDIR}/vls.cfg ${PKG_SYSCONFDIR}/vls.cfg

.include "../../multimedia/libdvdplay/buildlink2.mk"
.include "../../multimedia/libdvbpsi/buildlink2.mk"
.include "../../multimedia/libdvdread/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
