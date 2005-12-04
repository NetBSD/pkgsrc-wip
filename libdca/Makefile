# $NetBSD: Makefile,v 1.1.1.1 2005/12/04 22:04:14 shattered Exp $
#

DISTNAME=		libdts-0.0.2
PKGNAME=		libdca-0.0.2
CATEGORIES=		audio
MASTER_SITES=		http://debian.unnet.nl/pub/videolan/libdts/0.0.2/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://developers.videolan.org/libdca.html
COMMENT=		DTS Coherent Acoustics decoder

RESTRICTED=	"Unresolved patent issue"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libdts/libdts.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
