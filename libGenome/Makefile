# $NetBSD: Makefile,v 1.4 2012/10/03 09:10:36 asau Exp $
#

DISTNAME=		libGenome-0.5.2
CATEGORIES=		biology
MASTER_SITES=		http://www.libgenome.org/releases/
#EXTRACT_SUFX=		.tar.gz

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.libgenome.org/releases/
COMMENT=		A development library for bioinformatic software

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/libgenome-0.5.2
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
