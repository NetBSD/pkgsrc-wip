# $NetBSD: Makefile,v 1.4 2006/05/01 01:31:59 shattered Exp $
#

DISTNAME=		redland-0.9.14
CATEGORIES=		textproc
MASTER_SITES=		http://download.librdf.org/source/old/

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://download.librdf.org/source/
COMMENT=		Library for RDF in C, Java, Perl, PHP, Python, Ruby and Tcl

GNU_CONFIGURE=		YES

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
