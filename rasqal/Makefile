# $NetBSD: Makefile,v 1.2 2007/08/28 20:09:20 krub1 Exp $

DISTNAME=   rasqal-0.9.14

CATEGORIES=	textproc

MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=		mkirby@NetBSD.org
HOMEPAGE=		http://librdf.org/
COMMENT=		Library that handles RDF query syntaxes

USE_TOOLS+=	 gmake pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	rasqal.pc.in

.include "../../textproc/raptor/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
