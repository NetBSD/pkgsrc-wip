# $NetBSD: Makefile,v 1.2 2015/01/03 13:49:47 jonthn Exp $
#

DISTNAME=	v1.1.0
PKGNAME=	libuv-${DISTNAME:S/v//1}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libuv/libuv/archive/

HOMEPAGE=	http://nikhilm.github.com/uvbook/
COMMENT=	Asynchronous event library, platform layer of node.js
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

WRKSRC=		${WRKDIR}/libuv-${DISTNAME:S/v//1}

USE_TOOLS+=     autoconf automake aclocal gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

HEADERS=	uv-bsd.h uv-darwin.h uv-linux.h uv-sunos.h uv-unix.h uv-win.h

pre-configure:
	${RUN} cd ${WRKSRC} && sh autogen.sh

post-install:
	for f in ${HEADERS}; do						\
		${INSTALL_DATA} ${WRKSRC}/include/$$f ${DESTDIR}${PREFIX}/include/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
