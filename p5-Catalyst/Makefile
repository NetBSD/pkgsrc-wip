# $NetBSD: Makefile,v 1.5 2005/12/30 22:02:03 kuli0020 Exp $

DISTNAME=	Catalyst-5.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst/
COMMENT=	The Elegant MVC Web Application Framework
PERL5_REQD+=    5.8.1

DEPENDS+=       p5-UNIVERSAL-exports>=0.03:../../wip/p5-UNIVERSAL-exports
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=      	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=       {perl>=5.4.0,p5-CGI>=3.06}:../../www/p5-CGI
DEPENDS+=	p5-File-Modified>=0:../../wip/p5-File-Modified
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Body>=0.5:../../wip/p5-HTTP-Body
DEPENDS+=	p5-libwww>=5.801:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Request-AsCGI>=0:../../wip/p5-HTTP-Request-AsCGI
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types
DEPENDS+=	p5-Module-Pluggable-Fast>=0.16:../../wip/p5-Module-Pluggable-Fast
DEPENDS+=	p5-NEXT>=0:../../wip/p5-NEXT
DEPENDS+=	p5-Path-Class>=0.09:../../wip/p5-Path-Class
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-SimpleTable>=0:../../wip/p5-Text-SimpleTable
DEPENDS+=	p5-Test-MockObject>=0:../../wip/p5-Test-MockObject
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes
DEPENDS+=	p5-Tree-Simple>=0:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory>=0:../../wip/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
DEPENDS+=	p5-File-Copy-Recursive>=0:../../wip/p5-File-Copy-Recursive
DEPENDS+=	p5-Module-Install>=0:../../wip/p5-Module-Install
DEPENDS+=	p5-ExtUtils-AutoInstall>=0:../../devel/p5-ExtUtils-AutoInstall

#PERL5_MODULE_TYPE=      Module::Install
PERL5_PACKLIST= auto/Catalyst/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
