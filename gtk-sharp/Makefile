# $NetBSD: Makefile,v 1.16 2004/04/04 18:43:13 marc Exp $
#

DISTNAME=	gtk-sharp-0.18
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

PARSER_MK=	${WRKSRC}/parser/GAPI/Makefile.in

SUBST_CLASSES+=		gapi
SUBST_STAGE.gapi=	pre-configure
SUBST_FILES.gapi=	parser/GAPI/Makefile.in
SUBST_SED.gapi=		-e 's,%%PERL5_SITELIB%%,${PERL5_SITELIB},'

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/gtkhtml3/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
