# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:41 tvierling Exp $
#

DISTNAME=	News-Newsrc-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=News/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/News-Newsrc
COMMENT=	Perl module to manage newsrc files

DEPENDS+=	p5-Set-IntSpan>=1.07:../../devel/p5-Set-IntSpan

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/News/Newsrc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
