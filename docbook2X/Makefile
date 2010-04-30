# $NetBSD: Makefile,v 1.1.1.1 2010/04/30 10:10:18 thomasklausner Exp $
#

DISTNAME=	docbook2X-0.8.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook2x/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docbook2x.sourceforge.net/
COMMENT=	Convert DocBook documents into traditional Unix man page format
LICENSE=	mit

DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	p5-XML-NamespaceSupport-[0-9]*:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-SAX-Expat-[0-9]*:../../textproc/p5-XML-SAX-Expat
DEPENDS+=	tidy-[0-9]*:../../www/tidy

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	gmake makeinfo perl
CONFIGURE_ARGS+=	MAKEINFO=${MAKEINFO}
TEST_TARGET=	check

XML_CATALOGS=	${PREFIX}/share/docbook2X/dtd/catalog.xml
XML_CATALOGS+=	${PREFIX}/share/docbook2X/xslt/catalog.xml

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
