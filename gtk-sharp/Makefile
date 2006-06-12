# $NetBSD: Makefile,v 1.26 2006/06/12 16:37:06 thomasklausner Exp $
#

DISTNAME=	gtk-sharp-1.0.10
CATEGORIES=	x11
MASTER_SITES=	http://www.go-mono.com/sources/gtk-sharp/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gtk-sharp.sourceforge.net/
COMMENT=	.Net language binding for gtk+

DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_TOOLS+=	gmake perl:run pkg-config
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

# XXX work around a known mono bug
MONO=		${BUILDLINK_PREFIX.mono}/bin/mono --optimize=loop
MAKE_FLAGS+=	RUNTIME=${MONO:Q}

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/gtkhtml38/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
