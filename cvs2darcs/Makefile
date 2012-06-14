# $NetBSD: Makefile,v 1.3 2012/06/14 17:18:09 othyro Exp $
#

DISTNAME=		cvs2darcs-0.7.1
CATEGORIES=		devel
MASTER_SITES=		http://ab-initio.mit.edu/cvs2darcs/

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://ab-initio.mit.edu/cvs2darcs/
COMMENT=		Convert CVS repositories to Darcs version control
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

DEPENDS+=		cvsps>=2.1:../../devel/cvsps
DEPENDS+=		darcs-[0-9]*:../../devel/darcs
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

WRKSRC=			${WRKDIR}/cvs2darcs-0.7.1


.include "../../mk/bsd.pkg.mk"
