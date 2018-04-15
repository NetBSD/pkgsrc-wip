# $NetBSD: Makefile,v 1.7 2012/11/13 22:25:37 othyro Exp $
#

DISTNAME=		libGenome-0.5.2
CATEGORIES=		biology
MASTER_SITES=		http://pages.cs.wisc.edu/~darling/libgenome/releases/
LICENSE=		gnu-gpl-v2

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://pages.cs.wisc.edu/~darling/libgenome/
COMMENT=		Development library for bioinformatic software

WRKSRC=			${WRKDIR}/libgenome-0.5.2
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
