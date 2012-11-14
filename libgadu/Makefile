# $NetBSD: Makefile,v 1.7 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=	libgadu-1.9.0-rc2
PKGNAME=	${DISTNAME:S/-r/r/1}
CATEGORIES=	chat
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://toxygen.net/libgadu/
COMMENT=	Used by Instant Messengers with Gadu-Gadu support
LICENSE=	gnu-lgpl-v2.1

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
