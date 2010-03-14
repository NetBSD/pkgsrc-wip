# $NetBSD: Makefile,v 1.5 2010/03/14 23:03:55 shindenmorr Exp $
#

DISTNAME=	libgadu-1.9.0-rc2
PKGNAME=	libgadu-1.9.0rc2
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
REPLACE_PERL=	test/protocol/compile
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-openssl \
			--with-pthread 	  \
			--without-bind

PKGCONFIG_OVERRIDE+=	pkgconfig/libgadu.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
