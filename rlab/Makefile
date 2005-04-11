# $NetBSD: Makefile,v 1.3 2005/04/11 21:15:29 tvierling Exp $
#

DISTNAME=		rlab-2.1.05
CATEGORIES=		wip math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rlab/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://rlab.sourceforge.net/
COMMENT=		Matlab-like scientific programming environment

PKG_OPTIONS_VAR=	PKG_OPTIONS.rlab
PKG_SUPPORTED_OPTIONS=	gnuplot plplot

GNU_CONFIGURE=		yes
USE_LANGUAGES=		fortran c

.if !defined(PKG_OPTIONS.rlab)
PKG_DEFAULT_OPTIONS+=	gnuplot
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnuplot)
DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot
.endif

.if !empty(PKG_OPTIONS:Mplplot)
.  include "../../graphics/plplot/buildlink3.mk"
CONFIGURE_ARGS+=	--with-plplot=${BUILDLINK_PREFIX.plplot}/lib
.endif

CONFIGURE_ARGS+=	--with-LIBS=${PREFIX}/lib

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
