# $NetBSD: Makefile,v 1.1.1.1 2008/07/24 10:47:25 cryonator Exp $
#

DISTNAME=       Unicode-CheckUTF8-1.01
PKGNAME=        p5-${DISTNAME}
CATEGORIES=     converters perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://search.cpan.org/dist/Unicode-CheckUTF8/
COMMENT=        Perl5 module to check if scalar is valid UTF-8

PKG_DESTDIR_SUPPORT=    user-destdir

PERL5_PACKLIST=         auto/Unicode/CheckUTF8/.packlist

PERL5_PACKLIST=	auto/Unicode/CheckUTF8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
