# $NetBSD: Makefile,v 1.3 2010/11/05 04:20:26 shattered Exp $

DISTNAME=	Crypt-CAST5-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-CAST5/
COMMENT=	Perl5 CAST5 block cipher implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CRYPTO=		YES
PERL5_PACKLIST=	auto/Crypt/CAST5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
