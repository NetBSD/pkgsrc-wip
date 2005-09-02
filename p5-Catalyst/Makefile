# $NetBSD: Makefile,v 1.3 2005/09/02 17:06:58 kuli0020 Exp $

DISTNAME=	Catalyst-5.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst/
COMMENT=	The Elegant MVC Web Application Framework
PERL5_REQD+= 	5.8.1

DEPENDS+=	{perl>=5.4.0,p5-CGI>=3.06}:../../www/p5-CGI
DEPENDS+=	p5-UNIVERSAL-exports>=0:../../wip/p5-UNIVERSAL-exports
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-File-Temp>=0.14:../../devel/p5-File-Temp
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Module-Pluggable-Fast>=0.16:../../wip/p5-Module-Pluggable-Fast
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-ASCIITable>=0:../../wip/p5-Text-ASCIITable
DEPENDS+=	p5-Tree-Simple>=0:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory>=0:../../wip/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-Path-Class>=0.09:../../wip/p5-Path-Class

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/Catalyst/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
