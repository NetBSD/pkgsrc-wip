# $NetBSD: Makefile,v 1.6 2019/08/11 13:20:52 wiz Exp $

DISTNAME=	swig-4.0.2
PKGNAME=	${DISTNAME:S/swig/swig4/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 4)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-suffix=4.0
CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/4.0

BUILD_TARGET=	swig

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
