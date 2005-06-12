# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:24 kristerw Exp $

DISTNAME=	mxterm_129
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	wip
MASTER_SITES=	http://inittab.netizenweb.com/downloads/

MAINTAINER=	inittab@netizenweb.com
#HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
HOMEPAGE=	http://inittab.netizenweb.com/software.jsp
COMMENT=	Motif XTerm

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
