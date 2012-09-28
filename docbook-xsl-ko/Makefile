# $NetBSD: Makefile,v 1.7 2012/09/28 21:14:26 asau Exp $

DISTNAME=	docbook-xsl-ko-0.2
CATEGORIES=	textproc
MASTER_SITES=	http://download.kldp.net/docbook/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://docbook.or.kr/
COMMENT=	DocBook XSL customization layer for Korean

DEPENDS=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

NO_CONFIGURE=	YES
NO_BUILD=	YES

XSLDIR=		${PREFIX}/share/xsl/docbook-ko

XML_CATALOGS=	${XSLDIR}/catalog

SUBST_CLASSES+=		xsl
SUBST_MESSAGE.xsl=	Fixing remote URLs.
SUBST_STAGE.xsl=	post-patch
SUBST_FILES.xsl=	dbk-fo.xsl dbk-html-chunk.xsl dbk-html.xsl \
			dbk-htmlhelp.xsl
SUBST_SED.xsl=		-e 's,http://docbook.sourceforge.net/release/xsl/current/,../docbook/,g'

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xsl ${DESTDIR}${XSLDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DESTDIR}${XSLDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
