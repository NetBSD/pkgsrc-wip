#
# $NetBSD: Makefile,v 1.2 2005/03/03 17:29:50 airhead Exp $
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

USE_X11=		yes
USE_BUILDLINK3=		yes

PTHREAD_OPTS+=		require

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pre-build:
	${MKDIR} ${WRKSRC}/bin/pkgsrc

.include "../../mk/bsd.pkg.mk"
