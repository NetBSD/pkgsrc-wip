# $NetBSD: Makefile,v 1.1.1.1 2003/11/07 08:54:30 peterih Exp $
#

DISTNAME=		pointless-0.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pointless/}

MAINTAINER=		pih@bsdmail.dk
HOMEPAGE=		http://pointless.sourceforge.net/
COMMENT=		Markup-language presentation tool

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../lang/python22/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
