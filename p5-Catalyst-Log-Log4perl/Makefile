# $NetBSD: Makefile,v 1.5 2008/10/20 08:53:38 tonnerre Exp $

DISTNAME=	Catalyst-Log-Log4perl-0.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/H/HO/HOLOWAY/}

PERL5_REQD+=	5.8.0

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Log-Log4perl/
COMMENT=	Log::Log4perl logging for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.60:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Log-Log4perl>=0:../../devel/p5-Log-Log4perl
DEPENDS+=   p5-Params-Validate>=0:../../devel/p5-Params-Validate

PERL5_PACKLIST=		auto/Catalyst/Log/Log4perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
