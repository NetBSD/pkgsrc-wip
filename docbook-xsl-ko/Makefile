# $NetBSD: Makefile,v 1.3 2004/04/27 17:47:42 thomasklausner Exp $

DISTNAME=	docbook-xsl-ko-0.2
CATEGORIES=	textproc
MASTER_SITES=	http://download.kldp.net/docbook/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://docbook.or.kr/
COMMENT=	DocBook XSL customization layer for Korean

DEPENDS=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_BUILDLINK3=	YES

XSLDIR=		${PREFIX}/share/xsl/docbook-ko

XML_CATALOGS=	${XSLDIR}/catalog

SUBST_CLASSES+=		xsl
SUBST_MESSAGE.xsl=	"Fixing remote URLs."
SUBST_STAGE.xsl=	post-patch
SUBST_FILES.xsl=	dbk-fo.xsl dbk-html-chunk.xsl dbk-html.xsl \
			dbk-htmlhelp.xsl
SUBST_SED.xsl=		-e 's,http://docbook.sourceforge.net/release/xsl/current/,../docbook/,g'

do-install:
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xsl ${XSLDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${XSLDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
