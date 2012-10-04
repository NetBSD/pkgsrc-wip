# $NetBSD: Makefile,v 1.9 2012/10/04 09:13:29 asau Exp $

DISTNAME=	Catalyst-Plugin-Email-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Email/
COMMENT=	Send emails with Catalyst and Email::Send and Email::MIME::Creator

DEPENDS+=	p5-Email-MIME>=0:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-Creator>=0:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-Send>=0:../../mail/p5-Email-Send
DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST= auto/Catalyst/Plugin/Email/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
