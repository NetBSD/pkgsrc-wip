# $NetBSD: Makefile,v 1.1.1.1 2003/04/24 20:15:11 xtraeme Exp $
#

DISTNAME=	xml2doc-20030424
CATEGORIES=	textproc
MASTER_SITES=	http://xml2doc.sourceforge.net/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xml2doc.sourceforge.net/src/
COMMENT=	Xml to document formats converter

WRKSRC=         ${WRKDIR}/xml2doc

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

MANCOMPRESSED=		xml2doc.1.gz

.include "../../print/pdflib/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
