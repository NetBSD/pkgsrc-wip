# $NetBSD: Makefile,v 1.3 2013/08/19 09:18:06 nthauvin Exp $
#

DISTNAME=	pkgconf-0.9.2
CATEGORIES=	devel
MASTER_SITES=	http://tortois.es/~nenolod/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nico@orgrim.net
HOMEPAGE=	https://github.com/pkgconf/pkgconf
COMMENT=	API-driven pkg-config replacement
LICENSE=	modified-bsd

CONFLICTS+=	pkg-config-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${PREFIX}/share/pkgconfig \
		--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include

post-install:
	${LN} -s ${PREFIX}/bin/pkgconf ${DESTDIR}${PREFIX}/bin/pkg-config

.include "../../mk/bsd.pkg.mk"
