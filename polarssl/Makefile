# $NetBSD: Makefile,v 1.16 2012/11/19 14:41:35 christtrekker Exp $
#

DISTNAME=		polarssl-1.2.0-gpl
PKGNAME=		${DISTNAME:-gpl=}
CATEGORIES=		security devel
MASTER_SITES=		http://polarssl.org/code/releases/
EXTRACT_SUFX=		.tgz
FETCH_USING=		curl

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://polarssl.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl
REPLACE_PERL=		tests/scripts/*.pl
USE_LANGUAGES=		c
TEST_TARGET=		check

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
#TODO later
.endif

.include "../../mk/bsd.pkg.mk"
