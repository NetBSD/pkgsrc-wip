# $NetBSD: Makefile,v 1.3 2005/12/05 22:27:46 rillig Exp $

DISTNAME=		libmusclecard-1.2.9-beta7
PKGNAME=		libmusclecard-1.2.9
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/977/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.musclecard.com/
COMMENT=		MUSCLE SmartCard framework support library

GNU_CONFIGURE=          YES
USE_PKGINSTALL=         YES
USE_LIBTOOL=            YES
USE_TOOLS+=             automake gmake pkg-config

CONFIGURE_ARGS+=	--enable-muscledropdir=${PREFIX}/lib/pcsc-lite/drivers
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

pre-configure:
	cd ${WRKSRC} && \
	aclocal && \
	autoheader && \
	libtoolize --force && \
	automake --copy --add-missing && \
	autoconf

.include "../../wip/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
