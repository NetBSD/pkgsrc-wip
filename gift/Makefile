# $NetBSD: Makefile,v 1.1.1.1 2003/08/21 18:05:15 xtraeme Exp $
#

DISTNAME=	gift-0.11.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	Modular daemon that abstracts filesharing protocols	

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/lib/libgift.pc.in

PKG_SYSCONFSUBDIR=      gift

EGDIR=		${PREFIX}/share/examples/gift
CONF_FILES=	${EGDIR}/giftd.conf.template ${PKG_SYSCONFDIR}/giftd.conf
CONF_FILES+=	${EGDIR}/ui.conf.template ${PKG_SYSCONFDIR}/ui.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/giftd.conf.template \
		${WRKSRC}/etc/ui/ui.conf.template ${EGDIR}

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
