# $NetBSD: Makefile,v 1.3 2006/10/29 08:32:52 shattered Exp $
#

DISTNAME=	News-Newsrc-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=News/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/News-Newsrc/
COMMENT=	Perl module to manage newsrc files

DEPENDS+=	p5-Set-IntSpan>=1.07:../../devel/p5-Set-IntSpan

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/News/Newsrc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
