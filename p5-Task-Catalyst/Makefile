# $NetBSD: Makefile,v 1.7 2013/10/25 07:23:26 thomasklausner Exp $

DISTNAME=	Task-Catalyst-1.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Task-Catalyst/
COMMENT=	All you need to start with Catalyst
PERL5_REQD+=	5.8.0

DEPENDS+=	p5-Catalyst-Runtime>=5.65:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Params-Validate>=0:../../devel/p5-Params-Validate
DEPENDS+=	p5-Catalyst-Log-Log4perl>=0.1:../../wip/p5-Catalyst-Log-Log4perl
DEPENDS+=	p5-Date-Calc>=0:../../devel/p5-Date-Calc
DEPENDS+=	p5-Catalyst-Plugin-HTML-Widget>=1.1:../../wip/p5-Catalyst-Plugin-HTML-Widget
DEPENDS+=	p5-Catalyst-Plugin-StackTrace>=0.02:../../www/p5-Catalyst-Plugin-StackTrace
DEPENDS+=	p5-Catalyst-Plugin-Prototype>=1.32:../../wip/p5-Catalyst-Plugin-Prototype
DEPENDS+=	p5-Catalyst-Plugin-Singleton>=0.02:../../wip/p5-Catalyst-Plugin-Singleton
DEPENDS+=	p5-Catalyst-Plugin-DefaultEnd>=0.03:../../wip/p5-Catalyst-Plugin-DefaultEnd
DEPENDS+=	p5-Catalyst-Plugin-SubRequest>=0.10:../../wip/p5-Catalyst-Plugin-SubRequest
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.05:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Plugin-Session-Store-File>=0.07:../../www/p5-Catalyst-Plugin-Session-Store-File
DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie>=0.02:../../www/p5-Catalyst-Plugin-Session-State-Cookie
DEPENDS+=	p5-Catalyst-Plugin-Session-State-URI>=0.02:../../wip/p5-Catalyst-Plugin-Session-State-URI
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.05:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Plugin-Authentication-Store-Htpasswd>=0.02:../../wip/p5-Catalyst-Plugin-Authentication-Store-Htpasswd
DEPENDS+=	p5-Catalyst-Plugin-Authorization-ACL>=0.06:../../www/p5-Catalyst-Plugin-Authorization-ACL
DEPENDS+=	p5-Catalyst-Plugin-Authorization-Roles>=0.03:../../www/p5-Catalyst-Plugin-Authorization-Roles
DEPENDS+=	p5-Catalyst-Plugin-I18N>=0.05:../../www/p5-Catalyst-Plugin-I18N
DEPENDS+=	p5-XML-Parser>=0:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Catalyst-Plugin-XMLRPC>=0.06:../../wip/p5-Catalyst-Plugin-XMLRPC
DEPENDS+=	p5-Catalyst-Plugin-Pluggable>=0.04:../../wip/p5-Catalyst-Plugin-Pluggable
DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0.08:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-View-TT>=0.22:../../www/p5-Catalyst-View-TT
DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0.35:../../www/p5-Test-WWW-Mechanize-Catalyst
DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite


PERL5_PACKLIST=		auto/Task/Catalyst/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
