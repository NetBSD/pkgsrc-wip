# $NetBSD: Makefile,v 1.7 2004/04/24 23:26:27 thomasklausner Exp $
#

DISTNAME=	gift-0.11.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	alex@catbull.com
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	Modular daemon that abstracts filesharing protocols

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/lib/libgift.pc.in

EGDIR=		${PREFIX}/share/examples/gift

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/giftd.conf.template \
		${WRKSRC}/etc/ui/ui.conf.template ${EGDIR}

.include "../../devel/libtool/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
