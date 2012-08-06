# $NetBSD: Makefile,v 1.2 2012/08/06 15:04:46 mwilhelmy Exp $
#

DISTNAME=		polarssl-1.1.4-gpl
PKGNAME=		polarssl-1.1.4
CATEGORIES=		security devel
MASTER_SITES=		http://polarssl.org/code/download/
EXTRACT_SUFX=		.tgz

COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
HOMEPAGE=		http://polarssl.org/
LICENSE=		gnu-gpl-v2
MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/${PKGNAME}
REPLACE_PERL=		tests/scripts/*.pl

#USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
