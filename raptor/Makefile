# $NetBSD: Makefile,v 1.1.1.1 2003/04/28 01:34:17 xtraeme Exp $
#

DISTNAME=	raptor-0.9.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.redland.opensource.ac.uk/dist/source/
COMMENT=	RDF Parser Toolkit written in C

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/raptor.pc.in
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
