# $NetBSD: Makefile,v 1.6 2012/08/06 18:21:04 mwilhelmy Exp $
#

DISTNAME=		polarssl-1.1.4-gpl
PKGNAME=		${DISTNAME:-gpl=}
CATEGORIES=		security devel
MASTER_SITES=		http://polarssl.org/code/download/
EXTRACT_SUFX=		.tgz

COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
HOMEPAGE=		http://polarssl.org/
LICENSE=		gnu-gpl-v2
MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
REPLACE_PERL=		tests/scripts/*.pl
NO_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
