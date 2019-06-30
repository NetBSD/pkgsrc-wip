# $NetBSD: Makefile,v 1.5 2012/10/04 10:45:29 asau Exp $
#

DISTNAME=	Hash-AsObject-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	https://metacpan.org/release/Hash-AsObject
COMMENT=	Treat hashes as objects, with arbitrary accessors/mutators
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Hash/AsObject/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
