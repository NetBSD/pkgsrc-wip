# $NetBSD: Makefile,v 1.6 2012/10/04 10:45:28 asau Exp $

DISTNAME=	HTML-TagCloud-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTML-TagCloud/
COMMENT=	Generate An HTML Tag Cloud

DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	none

PERL5_REQD+=	5.6.0
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/HTML/TagCloud/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
