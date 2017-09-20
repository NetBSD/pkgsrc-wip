# $NetBSD: Makefile,v 1.2 2012/10/04 18:42:20 asau Exp $

DISTNAME=	Encode-Arabic-14.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SM/SMRZ/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://search.cpan.org/dist/Encode-Arabic/
COMMENT=	Perl5 implementation for Arabic encodings
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Encode/Arabic/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
