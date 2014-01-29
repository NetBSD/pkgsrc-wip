# $NetBSD: Makefile,v 1.1 2014/01/29 19:53:08 christtrekker Exp $

DISTNAME=	fontaine_svn_r57_2012.02.01
PKGNAME=	${DISTNAME:C/svn_r[[:digit:]]*_//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontaine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unifont.org/fontaine/
COMMENT=	CLI utility to display font meta information
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c++ c

BUILD_DEPENDS+=	doxygen:../../devel/doxygen
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
