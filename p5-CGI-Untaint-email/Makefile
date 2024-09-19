# $NetBSD: Makefile,v 1.2 2012/10/04 09:13:27 asau Exp $

DISTNAME=	CGI-Untaint-email-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/CGI::Untaint::email
COMMENT=	Validate an email address

DEPENDS+=	p5-CGI-Untaint>=0.07:../../wip/p5-CGI-Untaint
DEPENDS+=	p5-Email-Valid>=0.13:../../mail/p5-Email-Valid

PERL5_PACKLIST=	auto/CGI/Untaint/email/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
