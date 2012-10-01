# $NetBSD: Makefile,v 1.13 2012/10/01 09:01:15 mwilhelmy Exp $
#

DISTNAME=		polarssl-1.1.4-gpl
PKGNAME=		${DISTNAME:-gpl=}
CATEGORIES=		security devel
MASTER_SITES=		http://polarssl.org/code/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://polarssl.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
USE_LANGUAGES=		c
TEST_TARGET=		check

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
REPLACE_PERL=		tests/scripts/*.pl
.endif

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
