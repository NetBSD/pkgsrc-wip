# $NetBSD: Makefile,v 1.8 2006/11/11 11:31:03 shattered Exp $
#

DISTNAME=		redland-0.9.14
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://download.librdf.org/source/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://download.librdf.org/source/
COMMENT=		Library for RDF in C, Java, Perl, PHP, Python, Ruby and Tcl

GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-perl=yes
CONFIGURE_ARGS+=	--with-python=yes
#CONFIGURE_ARGS+=	--with-php=yes
#CONFIGURE_ARGS+=	--with-java=yes
#CONFIGURE_ARGS+=	--with-ruby=yes
#CONFIGURE_ARGS+=	--with-tcl=yes
#CONFIGURE_ARGS+=
#CONFIGURE_ARGS+=
#CONFIGURE_ARGS+=

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
