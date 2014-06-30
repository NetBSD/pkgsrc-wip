# $NetBSD: Makefile,v 1.1 2014/06/30 18:43:03 nros Exp $

DISTNAME=	tinyxml2-2.1.0
CATEGORIES=	textproc
MASTER_SITES=	-https://github.com/leethomason/tinyxml2/archive/${PKGVERSION}.tar.gz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.grinninglizard.com/tinyxml2/
COMMENT=	Simple, small and efficient C++ XML parser
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=tinyxml2.pc.in

.include "../../mk/bsd.pkg.mk"
