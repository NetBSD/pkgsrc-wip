# $NetBSD: Makefile,v 1.5 2008/10/20 10:10:18 tonnerre Exp $

DISTNAME=	Catalyst-Plugin-Authorization-ACL-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authorization-ACL/
COMMENT=	ACL support for Catalyst applications

DEPENDS+=	p5-Catalyst-Runtime>=5.7:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Throwable>=0:../../wip/p5-Class-Throwable
DEPENDS+=	p5-Tree-Simple-VisitorFactory>=0:../../devel/p5-Tree-Simple-VisitorFactory

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authorization/ACL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
