# $NetBSD: Makefile,v 1.8 2013/11/27 15:36:22 shindenmorr Exp $
#

DISTNAME=	libgadu-1.11.2
CATEGORIES=	chat
MASTER_SITES= 	http://github.com/wojtekka/libgadu/releases/download/1.11.2/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://libgadu.net/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
REPLACE_PERL=	test/protocol/compile
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-pthread 	  \
			--without-bind

PKGCONFIG_OVERRIDE+=	pkgconfig/libgadu.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
