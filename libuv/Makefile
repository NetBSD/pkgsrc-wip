# $NetBSD: Makefile,v 1.4 2015/02/21 16:15:06 jonthn Exp $
#

DISTNAME=	libuv-1.4.0
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/libuv/libuv/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/libuv/libuv
COMMENT=	Asynchronous event library, platform layer of node.js
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

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
