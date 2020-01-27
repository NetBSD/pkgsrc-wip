# $NetBSD: Makefile,v 1.2 2014/02/05 17:01:59 christtrekker Exp $

DISTNAME=	fontaine_svn_r57_2012.02.01
PKGNAME=	${DISTNAME:C/svn_r[[:digit:]]*_//:S/.//g:S/_/-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontaine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unifont.org/fontaine/
COMMENT=	CLI utility to display font meta information
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c++ c

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
