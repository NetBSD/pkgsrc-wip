# $NetBSD: Makefile,v 1.1 2011/10/16 21:24:05 ftigeot Exp $

VER=		3.1.0
DISTNAME=	8dc93ffd48cb80b738075ce37df8f915-libexttextcat-${VER}
PKGNAME=	libexttextcat-${VER:S/-//g}
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://cgit.freedesktop.org/libreoffice/libexttextcat/
COMMENT=	Text categorization library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME}

CONFLICTS+=	libtextcat-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
