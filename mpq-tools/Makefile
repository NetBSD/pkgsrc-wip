# $NetBSD: Makefile,v 1.1.1.1 2004/10/23 17:31:31 bencollver Exp $
#

DISTNAME=		mpq-tools-0.3.0
CATEGORIES=		archivers
MASTER_SITES=		http://babelize.org/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://babelize.org/
COMMENT=		Tools for manipulating MPQ (MoPaQ) archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin include lib share

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
