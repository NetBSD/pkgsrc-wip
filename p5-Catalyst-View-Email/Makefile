# $NetBSD: Makefile,v 1.1 2014/11/14 08:45:02 noud4 Exp $

DISTNAME=	Catalyst-View-Email-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/D/DH/DHOSS/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~dhoss/Catalyst-View-Email/
COMMENT=	Send Templated Email from Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.60000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent
DEPENDS+=	p5-Email-MIME-[0-9]*:../../mail/p5-Email-MIME
DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Email-Sender-[0-9]*:../../mail/p5-Email-Sender

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/Email/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
