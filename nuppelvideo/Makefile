# $NetBSD: Makefile,v 1.1.1.1 2003/11/13 19:30:16 grantbeattie Exp $
#

DISTNAME=		NuppelVideo-0.52a
CATEGORIES=		graphics audio
MASTER_SITES=		http://frost.htu.tuwien.ac.at/~roman/nuppelvideo/

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://frost.htu.tuwien.ac.at/~roman/nuppelvideo/
COMMENT=		Fast and simple RTjpeg-based video capture program

USE_BUILDLINK2=		YES
USE_X11=		YES

CFLAGS+=		${CPPFLAGS}
DEFS+=			${CPPFLAGS}

.include "../../mk/bsd.pkg.mk"
