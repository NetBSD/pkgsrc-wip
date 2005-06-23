# $NetBSD: Makefile,v 1.5 2005/06/23 23:18:59 minskim Exp $
#

DISTNAME=		WordNet-2.0
PKGNAME=		wordnet-2.0
CATEGORIES=		wip misc
MASTER_SITES=		ftp://ftp.cogsci.princeton.edu/pub/wordnet/2.0/	\
			ftp://ftp.ims.uni-stuttgart.de/pub/wordnet/2.0/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://wordnet.princeton.edu/
COMMENT=		English lexical reference system

BUILD_TARGET=		SrcWorld

PTHREAD_OPTS+=		require

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pre-build:
	${MKDIR} ${WRKSRC}/bin/pkgsrc

.include "../../mk/bsd.pkg.mk"
