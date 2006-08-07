# $NetBSD: Makefile,v 1.16 2006/08/07 09:21:53 kristerw Exp $

DISTNAME=       Catalyst-5.6902
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AG/AGRUNDMA/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst/
COMMENT=	The Elegant MVC Web Application Framework
PERL5_REQD+=    5.8.1

DEPENDS+=       p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=      	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Data-Visitor>=0.02:../../wip/p5-Data-Visitor
DEPENDS+=       {perl>=5.4.0,p5-CGI>=3.06}:../../www/p5-CGI
DEPENDS+=	p5-File-Modified>=0:../../devel/p5-File-Modified
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Body>=0.5:../../wip/p5-HTTP-Body
DEPENDS+=	p5-libwww>=5.805:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Request-AsCGI>=0.5:../../wip/p5-HTTP-Request-AsCGI
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types
DEPENDS+=	p5-Module-Pluggable-Fast>=0.16:../../wip/p5-Module-Pluggable-Fast
DEPENDS+=	p5-NEXT>=0:../../devel/p5-NEXT
DEPENDS+=	p5-Path-Class>=0.09:../../wip/p5-Path-Class
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-SimpleTable>=0.03:../../wip/p5-Text-SimpleTable
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes
DEPENDS+=	p5-Tree-Simple>=1.15:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory>=0:../../wip/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
DEPENDS+=	p5-File-Copy-Recursive>=0:../../wip/p5-File-Copy-Recursive
DEPENDS+=	p5-Module-Install>=0.54:../../devel/p5-Module-Install
DEPENDS+=	p5-YAML>=0.55:../../textproc/p5-YAML
BUILD_DEPENDS+=	p5-Test-MockObject>=0:../../wip/p5-Test-MockObject
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0.082:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST= auto/Catalyst/.packlist
MAKE_ENV+=      PERL_EXTUTILS_AUTOINSTALL=--skipdeps

# optional
# DEPENDS+=	p5-ExtUtils-AutoInstall>=0:../../devel/p5-ExtUtils-AutoInstall

# optional - Apache/mod_perl
# DEPENDS+=	p5-Catalyst-Engine-Apache>=0:../../wip/p5-Catalyst-Engine-Apache

# optional - FGCI
# DEPENDS+=	p5-FCGI>=0:../../www/p5-FCGI
# DEPENDS+=	p5-FCGI-ProcManager>=0:../../www/p5-FCGI-ProcManager

# optional - Test::WWW::Mechanize::Catalyst
# DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0:../../wip/p5-Test-WWW-Mechanize-Catalyst


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
