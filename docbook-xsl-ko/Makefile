# $NetBSD: Makefile,v 1.1.1.1 2003/12/19 22:54:52 minskim Exp $

DISTNAME=	docbook-xsl-ko-0.2
CATEGORIES=	textproc
MASTER_SITES=	http://download.kldp.net/docbook/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://docbook.or.kr/
COMMENT=	DocBook XSL customization layer for Korean

DEPENDS=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_BUILDLINK2=	YES

XSLDIR=		${PREFIX}/share/xsl/docbook-ko

XML_CATALOGS=	${XSLDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xsl ${XSLDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${XSLDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
