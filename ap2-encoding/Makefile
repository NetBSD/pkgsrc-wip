# $NetBSD: Makefile,v 1.3 2006/02/11 15:46:50 obache Exp $

DISTNAME=	mod_encoding-20021209
PKGNAME=	ap2-encoding-20040616
CATEGORIES=	www
MASTER_SITES=	http://webdav.todo.gr.jp/download/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://webdav.todo.gr.jp/
COMMENT=	Apache module for non-ascii filename interoperability

DISTFILE.main=	mod_encoding-20021209.tar.gz
DISTFILE.ap2=	mod_encoding.c.apache2.20040616
DISTFILES=	${DISTFILE.main} ${DISTFILE.ap2}
EXTRACT_ONLY=	${DISTFILE.main}
SITES_${DISTFILE.ap2}=	http://webdav.todo.gr.jp/download/experimental/

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
APACHE_MODULE=	yes

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-iconv_hook
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}

post-extract:
	${CP} ${DISTDIR:Q}/${DISTFILE.ap2:Q} ${WRKSRC:Q}/mod_encoding.c

.include "../../www/apache2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
