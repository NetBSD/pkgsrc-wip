# $NetBSD: Makefile,v 1.4 2004/04/05 13:30:19 thomasklausner Exp $

DISTNAME=		fakenes-0.1.5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fakenes/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://fakenes.sf.net/
COMMENT=		NES emulator using the allegro library

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CPPFLAGS+=		-DPREFIX=\"\\\"${PREFIX}\\\"\"

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
