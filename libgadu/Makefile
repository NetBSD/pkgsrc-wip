# $NetBSD: Makefile,v 1.4 2009/07/08 10:48:13 jihbed Exp $
#

DISTNAME=	libgadu-1.8.2
CATEGORIES=	wip
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://toxygen.net/libgadu/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=			  \
			--without-openssl \
			--with-pthread 	  \
			--without-bind

PKGCONFIG_OVERRIDE+=	pkgconfig/libgadu.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
