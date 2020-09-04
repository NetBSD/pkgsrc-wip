# $NetBSD$

DISTNAME=	HTML-Formatter-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://metacpan.org/release/HTML-Format/
COMMENT=	Format HTML as plaintext
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Build>=0.4:../../devel/p5-Module-Build
DEPENDS+=	p5-HTML-Parser>=3.7:../../www/p5-HTML-Parser
DEPENDS+=	p5-File-Slurper>=0:../../devel/p5-File-Slurper
DEPENDS+=	p5-HTML-Tree>=5.0:../../www/p5-HTML-Tree
DEPENDS+=	p5-Font-AFM>=1.2:../../fonts/p5-Font-AFM

PERL5_PACKLIST=	auto/HTML/Formatter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
