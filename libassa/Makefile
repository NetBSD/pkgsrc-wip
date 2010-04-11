# $NetBSD: Makefile,v 1.8 2010/04/11 08:38:23 obache Exp $
#

DISTNAME=		libassa-3.5.0
CATEGORIES=		devel net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libassa/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://libassa.sourceforge.net/
COMMENT=		Networking library based on ACP
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	${WRKSRC}/assa-3.5.pc.in

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-doxygen=no
CONFIGURE_ARGS+=	--enable-dot=no
CONFIGURE_ARGS+=	--enable-html-docs=no
CONFIGURE_ARGS+=	--enable-latex-docs=no

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_DEVELOPER) || defined(PKGSRC_RUN_TESTS) && !empty(PKGSRC_RUN_TESTS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-selftests
TEST_TARGET=		check
.endif

post-install:
	cd ${DESTDIR}${PREFIX} && ${LN} -s ../bin/assa-genesis-3.5 bin/assa-genesis
	cd ${DESTDIR}${PREFIX} && ${LN} -s ../bin/assa-hexdump-3.5 bin/assa-hexdump

.include "../../mk/bsd.pkg.mk"
