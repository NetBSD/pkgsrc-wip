# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:49 shattered Exp $

DISTNAME=	Catalyst-Log-Log4perl-0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/H/HO/HOLOWAY/}

PERL5_REQD+=	5.8.0

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Log-Log4perl/
COMMENT=	Log::Log4perl logging for Catalyst

DEPENDS+=	p5-Catalyst>=5.30:../../wip/p5-Catalyst
DEPENDS+=	p5-Log-Log4perl>=0:../../wip/p5-Log-Log4perl

PERL5_PACKLIST=		auto/Catalyst/Log/Log4perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
