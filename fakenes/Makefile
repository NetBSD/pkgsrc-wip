# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 22:54:50 blef Exp $

DISTNAME=		fakenes-0.1.5
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fakenes/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://fakenes.sf.net/
COMMENT=		NES emulator using the allegro library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CPPFLAGS+=		-DPREFIX=\"\\\"${PREFIX}\\\"\"

.include "../../devel/zlib/buildlink2.mk"
.include "../../wip/allegro/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
