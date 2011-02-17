# $NetBSD: Makefile,v 1.2 2011/02/17 21:01:41 zecrazytux Exp $
#

DISTNAME=	discount-2.0.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/discount/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://www.pell.portland.or.us/~orc/Code/discount/
COMMENT=	Markdown C implementation

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${DESTDIR}${PREFIX} \
			--execdir=${DESTDIR}${PREFIX}/bin \
			--libdir=${DESTDIR}${PREFIX}/lib \
			--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			--enable-all-features

INSTALL_TARGET=		install.everything
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
