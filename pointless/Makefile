# $NetBSD: Makefile,v 1.3 2004/05/07 14:37:57 peterih Exp $
#

DISTNAME=		pointless-0.5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pointless/}

MAINTAINER=		pih@bsdmail.dk
HOMEPAGE=		http://pointless.sourceforge.net/
COMMENT=		Markup-language presentation tool

DEPENDS+=               a2ps>=4.1:../../print/a2ps
DEPENDS+=               gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=               teTeX>=2.0:../../print/teTeX
DEPENDS+=               Mesa>=6.0:../../graphics/Mesa

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=		yes
USE_X11=		yes

INSTALL_TARGET=		${INSTALL} install-modules

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
