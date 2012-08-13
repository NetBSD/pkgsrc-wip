# $NetBSD: Makefile,v 1.11 2012/08/13 20:41:29 mwilhelmy Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c
REPLACE_PERL=		tests/scripts/*.pl

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
