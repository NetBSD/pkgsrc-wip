# $NetBSD: Makefile,v 1.5 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	Crypt-CAST5-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-CAST5/
COMMENT=	Perl5 CAST5 block cipher implementation

PERL5_PACKLIST=	auto/Crypt/CAST5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
