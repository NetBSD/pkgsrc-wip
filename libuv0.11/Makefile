# $NetBSD: Makefile,v 1.1 2014/11/22 22:52:41 jonthn Exp $
#

DISTNAME=	v0.11.29
PKGNAME=	libuv0.11-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/joyent/libuv/archive/

HOMEPAGE=	http://nikhilm.github.com/uvbook/
COMMENT=	Asynchronous event library, platform layer of node.js
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

WRKSRC=		${WRKDIR}/libuv-${DISTNAME:S/v//1}

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake gmake
USE_LIBTOOL=    yes

HEADERS=	uv-bsd.h uv-darwin.h uv-linux.h uv-sunos.h uv-unix.h uv-win.h

pre-configure:
	${RUN} cd ${WRKSRC} && sh autogen.sh

post-install:
	for f in ${HEADERS}; do						\
		${INSTALL_DATA} ${WRKSRC}/include/$$f ${DESTDIR}${PREFIX}/include/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
