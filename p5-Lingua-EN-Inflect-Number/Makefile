# $NetBSD: Makefile,v 1.1.1.1 2007/03/03 09:55:15 netcap Exp $
#

DISTNAME=	Lingua-EN-Inflect-Number-1.1
PKGNAME=	p5-${DISTNAME}
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SI/SIMON/}
#MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SI/SIMON/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/S/SI/SIMON/
COMMENT=	Force number of words to singular or plural

DEPENDS+=	p5-Lingua-EN-Inflect>=0:../../textproc/p5-Lingua-EN-Inflect

PERL5_PACKLIST=	auto/Lingua/EN/Inflect/Number/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
