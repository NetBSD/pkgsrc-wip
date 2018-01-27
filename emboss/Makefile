# $NetBSD: Makefile,v 1.6 2012/09/02 11:14:09 noud4 Exp $
#

DISTNAME=		EMBOSS-2.9.0
PKGNAME=		emboss-2.9.0
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		#empty
DISTFILES=		#empty

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://emboss.sourceforge.net/
COMMENT=		European Molecular Biology Open Software Suite

DEPENDS+=		emboss-base>=2.9.0:../../wip/emboss-base
DEPENDS+=		emboss-domainatrix>=1.0.0:../../wip/emboss-domainatrix
DEPENDS+=		emboss-emnu>=1.05:../../wip/emboss-emnu
DEPENDS+=		emboss-hmmer>=2.1.1:../../wip/emboss-hmmer
DEPENDS+=		emboss-meme>=2.3.1:../../wip/emboss-meme
#DEPENDS+=		emboss-mse>=1.0.0:../../wip/emboss-mse
DEPENDS+=		emboss-phylip>=3.57c:../../wip/emboss-phylip
DEPENDS+=		emboss-topo>=1.0.0:../../wip/emboss-topo

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	#empty

.include "../../mk/bsd.pkg.mk"
