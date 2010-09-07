# $NetBSD: Makefile,v 1.1.1.1 2010/09/07 00:56:29 jihbed Exp $
#

DISTNAME=	Encode-Arabic-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SMRZ/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://search.cpan.org/dist/Encode-Arabic/
COMMENT=	Perl5 implementation for Arabic encodings

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Encode/Arabic/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
