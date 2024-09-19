# $NetBSD: Makefile,v 1.5 2014/10/09 14:06:28 thomasklausner Exp $
#

DISTNAME=		mpq-tools-0.4.2
CATEGORIES=		archivers
MASTER_SITES=		https://libmpq.org/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://libmpq.org/
COMMENT=		Tools for manipulating MPQ (MoPaQ) archives

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../wip/libmpq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
