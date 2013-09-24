# $NetBSD: Makefile,v 1.1 2013/09/24 10:40:19 fhajny Exp $

DISTNAME=	sphinxbase-0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://cmusphinx.sourceforge.net/
COMMENT=	CMU Sphinx Speech recognition system base
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	sphinxbase.pc.in

REPLACE_PERL+=		src/sphinx_lmtools/sphinx_lm_sort

CONFIGURE_ARGS+=	--without-lapack
CONFIGURE_ARGS+=	--without-python

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
