# $NetBSD: Makefile,v 1.2 2012/10/04 09:13:26 asau Exp $

DISTNAME=	CGI-Untaint-date-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TM/TMTM/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/CGI::Untaint::date
COMMENT=	CGI::Untaint::date - validate a date

DEPENDS+=	p5-CGI-Untaint>=0.07:../../wip/p5-CGI-Untaint
DEPENDS+=	p5-Date-Manip>=5:../../devel/p5-Date-Manip
DEPENDS+=	p5-Date-Simple>=0.01:../../devel/p5-Date-Simple

PERL5_PACKLIST=	auto/CGI/Untaint/date/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
