# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:56 asau Exp $
#

DISTNAME=		cvs2darcs-0.7.1
CATEGORIES=		devel
MASTER_SITES=		http://ab-initio.mit.edu/cvs2darcs/

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://ab-initio.mit.edu/cvs2darcs/
COMMENT=		Convert CVS repositories to Darcs version control
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

DEPENDS+=		cvsps>=2.1:../../devel/cvsps
DEPENDS+=		darcs-[0-9]*:../../devel/darcs
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

WRKSRC=			${WRKDIR}/cvs2darcs-0.7.1


.include "../../mk/bsd.pkg.mk"
