# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=	scscp-0.6.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://www.imcce.fr/trip/scscp/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.imcce.fr/trip/scscp/
COMMENT=	Library of the Symbolic Computation Software Composibility Protocol

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LANGUAGES=	c c++

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
