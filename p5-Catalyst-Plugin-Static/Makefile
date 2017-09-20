# $NetBSD: Makefile,v 1.6 2012/10/04 09:13:31 asau Exp $

DISTNAME=	Catalyst-Plugin-Static-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Static/
COMMENT=	Serve static files with Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-File-MimeInfo>=0.11:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST= auto/Catalyst/Plugin/Static/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
