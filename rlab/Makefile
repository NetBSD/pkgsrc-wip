# $NetBSD: Makefile,v 1.7 2006/08/16 20:14:48 dhowland Exp $
#

DISTNAME=		rlab-2.1.05
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rlab/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://rlab.sourceforge.net/
COMMENT=		Matlab-like scientific programming environment

GNU_CONFIGURE=		yes
USE_LANGUAGES=		fortran c

PKG_OPTIONS_VAR=	PKG_OPTIONS.rlab
PKG_SUPPORTED_OPTIONS=	gnuplot plplot
PKG_SUGGESTED_OPTIONS=	gnuplot

.include "../../mk/bsd.options.mk"

PLIST_SRC=		# empty

.if !empty(PKG_OPTIONS:Mgnuplot)
DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot
PLIST_SRC+=		${PKGDIR}/PLIST.gnuplot
.endif

.if !empty(PKG_OPTIONS:Mplplot)
.  include "../../graphics/plplot/buildlink3.mk"
CONFIGURE_ARGS+=	--with-plplot=${BUILDLINK_PREFIX.plplot}/lib
PLIST_SRC+=		${PKGDIR}/PLIST.plplot
.endif

CONFIGURE_ARGS+=	--with-LIBS=${PREFIX}/lib
PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
