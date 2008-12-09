# $NetBSD: Makefile,v 1.7 2008/12/09 21:40:00 bartoszkuzma Exp $
#

DISTNAME=		libassa-3.5.0
CATEGORIES=		devel net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libassa/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://libassa.sourceforge.net/
COMMENT=		Networking library based on ACP

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	${WRKSRC}/assa-3.5.pc.in

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-doxygen=no
CONFIGURE_ARGS+=	--enable-dot=no
CONFIGURE_ARGS+=	--enable-html-docs=no
CONFIGURE_ARGS+=	--enable-latex-docs=no

post-install:
	cd ${PREFIX} && ${LN} -s ../bin/assa-genesis-3.5 bin/assa-genesis
	cd ${PREFIX} && ${LN} -s ../bin/assa-hexdump-3.5 bin/assa-hexdump

.include "../../mk/bsd.pkg.mk"
