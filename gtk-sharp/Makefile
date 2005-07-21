# $NetBSD: Makefile,v 1.23 2005/07/21 16:34:00 thomasklausner Exp $
#

DISTNAME=	gtk-sharp-0.99
CATEGORIES=	x11
MASTER_SITES=	http://www.go-mono.com/archive/rc/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gtk-sharp.sourceforge.net/
COMMENT=	.Net language binding for gtk+

DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_TOOLS+=	gmake
USE_PERL5=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
PERL5_SITELIB=	yes

PKGCONFIG_OVERRIDE=	gtk-sharp.pc.in
PKGCONFIG_OVERRIDE+=	art/art-sharp.pc.in
PKGCONFIG_OVERRIDE+=	gconf/GConf/gconf-sharp.pc.in
PKGCONFIG_OVERRIDE+=	gda/gda-sharp.pc.in
PKGCONFIG_OVERRIDE+=	glade/glade-sharp.pc.in
PKGCONFIG_OVERRIDE+=	gnome/gnome-sharp.pc.in
PKGCONFIG_OVERRIDE+=	gnomedb/gnomedb-sharp.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/gtkhtml-sharp.pc.in
PKGCONFIG_OVERRIDE+=	parser/gapi.pc.in
PKGCONFIG_OVERRIDE+=	rsvg/rsvg-sharp.pc.in
PKGCONFIG_OVERRIDE+=	vte/vte-sharp.pc.in

REPLACE_PERL+=	parser/gapi-parser
REPLACE_PERL+=	parser/gapi.pl
REPLACE_PERL+=	parser/gapi2xml.pl
REPLACE_PERL+=	parser/gapi_pp.pl

PARSER_MK=	${WRKSRC}/parser/GAPI/Makefile.in

SUBST_CLASSES+=		gapi
SUBST_STAGE.gapi=	pre-configure
SUBST_FILES.gapi=	parser/GAPI/Makefile.in
SUBST_SED.gapi=		-e 's,%%PERL5_SITELIB%%,${PERL5_SITELIB},'

# XXX work around a known mono bug
MONO=		${BUILDLINK_PREFIX.mono}/bin/mono --optimize=loop
MAKE_FLAGS+=	RUNTIME=${MONO:Q}

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/gtkhtml3/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
