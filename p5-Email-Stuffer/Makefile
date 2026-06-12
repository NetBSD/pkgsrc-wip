# $NetBSD$

DISTNAME=	Email-Stuffer-0.020
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rjbs/Email-Stuffer
COMMENT=	More casual approach to creating and sending Email:: emails
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Email-MIME-[0-9]*:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-Sender-[0-9]*:../../mail/p5-Email-Sender
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/Email/Stuffer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
