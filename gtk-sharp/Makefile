# $NetBSD: Makefile,v 1.13 2004/03/21 10:30:14 marc Exp $
#

DISTNAME=	gtk-sharp-0.17
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-sharp/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gtk-sharp.sourceforge.net/
COMMENT=	.Net language binding for gtk+

DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_GNU_TOOLS+=	make
USE_PERL5=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
PERL5_SITELIB=	yes

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

.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
