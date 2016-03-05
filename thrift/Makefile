# $NetBSD$

DISTNAME=	thrift-0.9.3
CATEGORIES=	devel
MASTER_SITES=	https://archive.apache.org/dist/thrift/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thrift.apache.org/
COMMENT=	Framework for cross-language services development
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config automake autoconf aclocal lex yacc gmake autoscan autoheader
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/c_glib/thrift_c_glib.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift-nb.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift-qt.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift-z.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift.pc.in

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && \
		autoscan && \
		libtoolize --copy --automake && \
		aclocal -I ./aclocal && \
		autoheader && \
		autoconf && \
		automake --copy --add-missing --foreign

.include "../../mk/bsd.pkg.mk"
