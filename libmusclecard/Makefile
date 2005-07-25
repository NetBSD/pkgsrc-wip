# $NetBSD: Makefile,v 1.1.1.1 2005/07/25 17:33:10 udontknow Exp $

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
USE_TOOLS+=             automake gmake

CONFIGURE_ARGS+=	--enable-muscledropdir=${PREFIX}/lib/pcsc-lite/drivers
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

pre-configure:
	cd ${WRKSRC} && \
	aclocal && \
	autoheader && \
	libtoolize --force && \
	automake --copy --add-missing && \
	autoconf

.include "../../wip/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
