# $NetBSD: Makefile,v 1.2 2009/07/28 11:09:07 jihbed Exp $
#

DISTNAME=	fastrpc-1.0.13
CATEGORIES=	net
MASTER_SITES=	http://downloads.sourceforge.net/sourceforge/fastrpc/

MAINTAINER=	ondrej.tuma@firma.seznam.cz
HOMEPAGE=	http://downloads.sourceforge.net/sourceforge/fastrpc/
COMMENT=	Protocol based on the XML-RPC which uses binary format for data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fastrpc-1.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
