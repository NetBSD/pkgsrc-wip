# $NetBSD: Makefile,v 1.4 2012/03/03 15:28:15 ftigeot Exp $

VER=		3.2.0
DISTNAME=	libexttextcat-${VER}
PKGNAME=	libexttextcat-${VER:S/-//g}
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://cgit.freedesktop.org/libreoffice/libexttextcat/
COMMENT=	Text categorization library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFLICTS+=	libtextcat-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
