# $NetBSD: Makefile,v 1.6 2005/06/12 23:51:25 kristerw Exp $
#

DISTNAME=		pointless-0.5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pointless/}

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://pointless.sourceforge.net/
COMMENT=		Markup-language presentation tool

DEPENDS+=               a2ps>=4.1:../../print/a2ps
DEPENDS+=               gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=               teTeX>=2.0:../../print/teTeX
DEPENDS+=               Mesa>=6.0:../../graphics/Mesa

USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		${INSTALL} install-modules

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python22/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
