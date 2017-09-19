# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:27 asau Exp $

DISTNAME=	Catalyst-Log-Log4perl-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Log-Log4perl/
COMMENT=	Log::Log4perl logging for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.60:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Log-Log4perl>=0.49:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Params-Validate>=0:../../devel/p5-Params-Validate
DEPENDS+=	p5-Sub-Install>=0:../../devel/p5-Sub-Install
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=		auto/Catalyst/Log/Log4perl/.packlist
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
