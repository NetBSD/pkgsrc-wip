# $NetBSD: Makefile,v 1.2 2004/07/18 15:50:17 ppostma Exp $
#

DISTNAME=		redland-0.9.14
CATEGORIES=		textproc
MASTER_SITES=		http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://www.redland.opensource.ac.uk/dist/source/
COMMENT=		Library for RDF in C, Java, Perl, PHP, Python, Ruby and Tcl

GNU_CONFIGURE=		YES
GMAKE=			YES

CONFIGURE_ARGS+=	--with-perl=yes
CONFIGURE_ARGS+=	--with-python=yes
#CONFIGURE_ARGS+=	--with-php=yes
#CONFIGURE_ARGS+=	--with-java=yes
#CONFIGURE_ARGS+=	--with-ruby=yes
#CONFIGURE_ARGS+=	--with-tcl=yes
#CONFIGURE_ARGS+=
#CONFIGURE_ARGS+=
#CONFIGURE_ARGS+=

.include "../../mk/bsd.pkg.mk"
