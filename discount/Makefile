# $NetBSD: Makefile,v 1.5 2012/09/28 21:24:36 asau Exp $
#

DISTNAME=	discount-2.0.9
CATEGORIES=	textproc
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/discount/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://www.pell.portland.or.us/~orc/Code/discount/
COMMENT=	Markdown C implementation
LICENSE=	modified-bsd

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--execdir=${PREFIX}/bin \
			--libdir=${PREFIX}/lib \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--enable-all-features

INSTALL_TARGET=		install.everything
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
