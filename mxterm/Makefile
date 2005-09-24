# $NetBSD: Makefile,v 1.7 2005/09/24 11:37:32 gregschenzel Exp $

DISTNAME=	mxterm_129
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	x11
MASTER_SITES=	http://www.unixdev.net/downloads/mxterm/129/

MAINTAINER=	inittab@unixdev.net
#HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
HOMEPAGE=	http://www.unixdev.net/projects/mxterm
COMMENT=	Motif XTerm

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
