# $NetBSD: Makefile,v 1.6 2012/10/04 09:13:31 asau Exp $

DISTNAME=	Catalyst-Plugin-SubRequest-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-SubRequest/
COMMENT=	Serve static files from config->{root}

DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Plugin/SubRequest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
