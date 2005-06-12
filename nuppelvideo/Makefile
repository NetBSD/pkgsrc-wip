# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:24 kristerw Exp $
#

DISTNAME=		NuppelVideo-0.52a
CATEGORIES=		graphics audio
MASTER_SITES=		http://frost.htu.tuwien.ac.at/~roman/nuppelvideo/

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://frost.htu.tuwien.ac.at/~roman/nuppelvideo/
COMMENT=		Fast and simple RTjpeg-based video capture program

CFLAGS+=		${CPPFLAGS}
DEFS+=			${CPPFLAGS}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
