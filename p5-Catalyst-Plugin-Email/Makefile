# $NetBSD: Makefile,v 1.3 2006/02/24 19:57:01 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Email-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Email
COMMENT=	Send emails with Catalyst and Email::Send and Email::MIME::Creator

DEPENDS+=	p5-Email-MIME>=0:../../wip/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-Creator>=0:../../wip/p5-Email-MIME-Creator
DEPENDS+=	p5-Email-Send>=0:../../wip/p5-Email-Send
DEPENDS+=	p5-Catalyst>=2.99:../../wip/p5-Catalyst

PERL5_PACKLIST= auto/Catalyst/Plugin/Email/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
