# $NetBSD: Makefile,v 1.1.1.1 2005/08/26 21:45:47 kuli0020 Exp $

DISTNAME=	Email-MIME-1.82
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME/
COMMENT=	Easy MIME message parsing

DEPENDS+=	p5-Email-Simple>=1.91:../../mail/p5-Email-Simple
DEPENDS+=	p5-Email-MIME-Encodings>=1.3:../../mail/p5-Email-MIME-Encodings
DEPENDS+=	p5-Email-MIME-ContentType>=1.0:../../mail/p5-Email-MIME-ContentType
DEPENDS+=	p5-MIME-Types>=1.13:../../mail/p5-MIME-Types
DEPENDS+=	{perl>=5.7.3,p5-MIME-tools>=0}:../../mail/p5-MIME-tools
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
