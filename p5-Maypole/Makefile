# $NetBSD: Makefile,v 1.6 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Maypole-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TE/TEEJAY/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/Maypole
COMMENT=	Maypole - MVC web application framework

DEPENDS+=	p5-CGI-Simple>=0:../../www/p5-CGI-Simple
DEPENDS+=	p5-CGI-Untaint>=1.26:../../wip/p5-CGI-Untaint
DEPENDS+=	p5-CGI-Untaint-email>=0:../../wip/p5-CGI-Untaint-email
DEPENDS+=	p5-CGI-Untaint-date>=0:../../wip/p5-CGI-Untaint-date
DEPENDS+=	p5-Class-DBI>=0.96:../../databases/p5-Class-DBI
DEPENDS+=	p5-Class-DBI-AbstractSearch>=0:../../databases/p5-Class-DBI-AbstractSearch
DEPENDS+=	p5-Class-DBI-Loader>=0.02:../../wip/p5-Class-DBI-Loader
DEPENDS+=	p5-Class-DBI-Loader-Relationship>=0:../../wip/p5-Class-DBI-Loader-Relationship
DEPENDS+=	p5-Class-DBI-Pager>=0:../../wip/p5-Class-DBI-Pager
DEPENDS+=	p5-Class-DBI-Plugin-RetrieveAll>=0:../../wip/p5-Class-DBI-Plugin-RetrieveAll
DEPENDS+=	p5-Class-DBI-Plugin-Type>=0:../../wip/p5-Class-DBI-Plugin-Type
DEPENDS+=	p5-Class-DBI-SQLite>=0.08:../../wip/p5-Class-DBI-SQLite
DEPENDS+=	p5-File-MMagic-XS>=0.08:../../misc/p5-File-MMagic-XS
DEPENDS+=	p5-HTML-Tree>=0:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTTP-Body>=0.5:../../www/p5-HTTP-Body
DEPENDS+=	p5-Template-Plugin-Class>=0:../../wip/p5-Template-Plugin-Class
DEPENDS+=	p5-Test-MockModule>=0:../../devel/p5-Test-MockModule
DEPENDS+=	p5-UNIVERSAL-moniker>=0:../../devel/p5-UNIVERSAL-moniker
DEPENDS+=	p5-UNIVERSAL-require>=0:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI>=0:../../www/p5-URI


PERL5_PACKLIST=	auto/Maypole/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
