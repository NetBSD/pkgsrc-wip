# $NetBSD: Makefile,v 1.1.1.1 2008/02/27 03:18:02 ficovh Exp $
#

DISTNAME=	CGI-Untaint-email-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MIYAGAWA/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MI/MIYAGAWA/
COMMENT=	Validate an email address

DEPENDS+=	p5-CGI-Untaint>=0.07:../../wip/p5-CGI-Untaint
DEPENDS+=	p5-Email-Valid>=0.13:../../mail/p5-Email-Valid

PERL5_PACKLIST=	auto/CGI/Untaint/email/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
