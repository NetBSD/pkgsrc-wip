# $NetBSD: Makefile,v 1.20 2026/01/04 21:21:00 wiz Exp $

DISTNAME=		discount-3.0.2.0
PKGNAME=		${DISTNAME:S/discount/discount3/}
CATEGORIES=		textproc
MASTER_SITES=		https://www.pell.portland.or.us/~orc/Code/discount/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.pell.portland.or.us/~orc/Code/discount/
COMMENT=		Markdown C implementation
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME}

CONFLICTS+=		discount-[0-9]*
CONFLICTS+=		multimarkdown-[0-9]*

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--execdir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--shared
CONFIGURE_ARGS+=	--enable-all-features

USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libmarkdown.pc.in

INSTALL_TARGET=		install.everything
TEST_TARGET=		test

# test status: ends with:
# recursion limits ...............................................tests/limits.t: limits: 398: not found
# tests/limits.t: limits: 400: not found
# tests/limits.t: limits: 602: not found
# OK
# *** Error code 1

.include "../../mk/bsd.pkg.mk"
