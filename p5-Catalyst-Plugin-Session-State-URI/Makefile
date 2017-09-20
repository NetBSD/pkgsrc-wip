# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:30 asau Exp $

DISTNAME=	Catalyst-Plugin-Session-State-URI-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-URI/
COMMENT=	Saves Catalyst Session IDs by rewriting URIs

DEPENDS+=	p5-URI>=1.72:../../www/p5-URI
DEPENDS+=	p5-HTML-TokeParser-Simple>=0:../../www/p5-HTML-TokeParser-Simple
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types
DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject
DEPENDS+=	p5-URI-Find>=0:../../www/p5-URI-Find
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
# despite the dependencies, the package does not find these three and
# installs them manually
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.27:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast-[0-9]*:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/State/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
