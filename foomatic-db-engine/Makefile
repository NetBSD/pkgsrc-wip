# $NetBSD: Makefile,v 1.7 2006/05/19 16:51:16 ykomatsu Exp $

DISTNAME=	foomatic-db-engine-3.0.2
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

DEPENDS+=	foomatic-filters>=3.0.2:../../print/foomatic-filters
DEPENDS+=	foomatic-db-[0-9]*:../../wip/foomatic-db

GNU_CONFIGURE=	YES

USE_TOOLS+=	gmake perl
PERL5_REQD=	5.6
REPLACE_PERL+=	makeMan makeDefaults

PERL5_PACKLIST=	auto/Foomatic/.packlist

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
