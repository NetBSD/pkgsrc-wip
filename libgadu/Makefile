# $NetBSD: Makefile,v 1.9 2015/07/05 13:03:29 krytarowski Exp $
#

DISTNAME=	libgadu-1.12.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojtekka/}

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://libgadu.net/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	autoreconf autoconf automake
REPLACE_PERL=	test/protocol/compile
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-pthread 	  \
			--without-bind

PKGCONFIG_OVERRIDE+=	pkgconfig/libgadu.pc.in

pre-configure:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh NOCONFIGURE=1

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
