# $NetBSD: Makefile,v 1.2 2003/07/21 17:33:19 marttikuparinen Exp $
#

DISTNAME=	CDDB-1.08
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCAPUTO/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?module=CDDB
COMMENT=	High-level interface to the Compact Disc Database

USE_BUILDLINK2=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CDDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
