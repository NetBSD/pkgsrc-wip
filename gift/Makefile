# $NetBSD: Makefile,v 1.5 2004/02/17 02:55:32 blef Exp $
#

DISTNAME=	gift-0.11.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	Modular daemon that abstracts filesharing protocols

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/lib/libgift.pc.in

EGDIR=		${PREFIX}/share/examples/gift

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/giftd.conf.template \
		${WRKSRC}/etc/ui/ui.conf.template ${EGDIR}

.include "../../devel/libtool/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
