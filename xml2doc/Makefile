# $NetBSD: Makefile,v 1.4 2004/01/30 18:24:19 minskim Exp $
#

DISTNAME=	xml2doc-20030424
WRKSRC=         ${WRKDIR}/xml2doc
CATEGORIES=	textproc
MASTER_SITES=	http://xml2doc.sourceforge.net/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xml2doc.sourceforge.net/
COMMENT=	Xml to document formats converter

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

MANCOMPRESSED=		xml2doc.1.gz

.include "../../print/pdflib/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
