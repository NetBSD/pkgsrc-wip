# $NetBSD: Makefile,v 1.10 2004/01/25 02:23:02 grantbeattie Exp $
#

DISTNAME=	gtk-sharp-0.14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-sharp/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gtk-sharp.sourceforge.net/
COMMENT=	.Net language binding for gtk+

DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_PERL5=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
PERL5_SITELIB=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	gtk-sharp.pc.in
PKGCONFIG_OVERRIDE+=	parser/gapi.pc.in

REPLACE_PERL=	mapdllnames.pl
REPLACE_PERL+=	bin/gapi.pl
REPLACE_PERL+=	bin/gapi2xml.pl
REPLACE_PERL+=	bin/gapi_pp.pl

PARSER_MK=	${WRKSRC}/parser/Makefile.in

post-patch:
	${SED} -e 's,%%PERL5_SITELIB%%,${PERL5_SITELIB},' \
		${PARSER_MK} > ${PARSER_MK}.new
	${MV} ${PARSER_MK}.new ${PARSER_MK}

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../lang/mono/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
