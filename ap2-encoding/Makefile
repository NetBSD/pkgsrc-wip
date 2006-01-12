# $NetBSD: Makefile,v 1.2 2006/01/12 12:28:23 obache Exp $

DISTNAME=	mod_encoding-20021209
PKGNAME=        ap2-encoding-20040616
CATEGORIES=	www
MASTER_SITES=	http://webdav.todo.gr.jp/download/
DISTFILE.main=	mod_encoding-20021209.tar.gz
DISTFILE.ap2=	mod_encoding.c.apache2.20040616
DISTFILES=	${DISTFILE.main} ${DISTFILE.ap2}
EXTRACT_ONLY=	${DISTFILE.main}
SITES_${DISTFILE.ap2} = http://webdav.todo.gr.jp/download/experimental/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://webdav.todo.gr.jp/
COMMENT=        Apache module for non-ascii filename interoperability

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
APACHE_MODULE=	yes

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-iconv_hook
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}

post-extract:
	${CP} ${DISTDIR}/${DISTFILE.ap2} ${WRKSRC}/mod_encoding.c

.include "../../www/apache2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
