# $NetBSD: Makefile,v 1.3 2005/05/09 08:25:29 gregschenzel Exp $

DISTNAME=	mxterm_129
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	wip
MASTER_SITES=	http://inittab.netizenweb.com/downloads/

MAINTAINER=	inittab@netizenweb.com
#HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
HOMEPAGE=	http://inittab.netizenweb.com/software.jsp
COMMENT=	Motif XTerm

GNU_CONFIGURE=	YES
USE_X11=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

