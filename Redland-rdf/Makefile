# $NetBSD: Makefile,v 1.1.1.1 2003/09/09 01:13:24 mjasm Exp $
#

DISTNAME=		redland-0.9.14
CATEGORIES=		wip
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
