# $NetBSD: Makefile,v 1.7 2012/09/24 17:14:39 asau Exp $
#

DISTNAME=		brltty-3.7
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.mielke.cc/brltty/releases/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.mielke.cc/brltty/
COMMENT=		Access software for a blind person using a soft braille terminal
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/brltty
CONF_FILES=		${EGDIR}/brlapi.key ${PKG_SYSCONFDIR}/brlapi.key
CONF_FILES+=		${EGDIR}/brltty.conf ${PKG_SYSCONFDIR}/brltty.conf

MAKE_ENV+=		EGDIR=${EGDIR}
CONFIGURE_ARGS+=	--without-viavoice
CONFIGURE_ARGS+=	--without-theta
CONFIGURE_ARGS+=	--without-swift
CONFIGURE_ARGS+=	--without-flite
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--disable-speech-support
CONFIGURE_ARGS+=	--with-data-directory=${PREFIX}/share/brltty

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/Documents/brltty.conf ${EGDIR}

.include "../../devel/at-spi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
