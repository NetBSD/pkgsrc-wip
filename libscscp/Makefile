# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:26:06 jihbed Exp $
#

DISTNAME=	scscp-0.6.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://www.imcce.fr/trip/scscp/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.imcce.fr/trip/scscp/
COMMENT=  Library of the Symbolic Computation Software Composibility Protocol

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LANGUAGES=	c c++

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
