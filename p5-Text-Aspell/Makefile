# $NetBSD: Makefile,v 1.1.1.1 2008/02/12 11:10:32 shattered Exp $

DISTNAME=		Text-Aspell-0.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Aspell/
COMMENT=		Perl interface to the GNU Aspell library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Aspell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
