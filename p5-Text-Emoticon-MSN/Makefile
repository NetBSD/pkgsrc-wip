# $NetBSD: Makefile,v 1.2 2005/09/02 18:11:41 kuli0020 Exp $

DISTNAME=       Text-Emoticon-MSN-0.02
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	kuli0020@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Text-Emoticon-MSN
COMMENT=	Emoticon filter of MSN Messenger

DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Text/Emoticon/MSN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
