# $NetBSD: Makefile,v 1.1.1.1 2005/02/13 12:35:56 ppostma Exp $

DISTNAME=		ipfm-0.11.5
CATEGORIES=		net
MASTER_SITES=		http://robert.cheramy.net/ipfm/archive/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://robert.cheramy.net/ipfm/
COMMENT=		Bandwidth analysis tool

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

EGDIR=			${PREFIX}/share/examples/ipfm
CONF_FILES=		${EGDIR}/ipfm.conf ${PKG_SYSCONFDIR}/ipfm.conf

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8.3

post-install:
	@${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ipfm.conf.sample ${EGDIR}/ipfm.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
