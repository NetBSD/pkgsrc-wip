# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:27 asau Exp $

DISTNAME=	Exporter-Tidy-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/Exporter-Tidy
COMMENT=	Alternative way of exporting symbols in perl
# In fact the license says:
# Pick your favourite OSI approved license :)
LICENSE=	modified-bsd

PERL5_PACKLIST=	auto/Exporter/Tidy/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
