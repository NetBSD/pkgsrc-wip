# $NetBSD: Makefile,v 1.2 2008/01/12 23:32:08 thomasklausner Exp $

DISTNAME=	Catalyst-Plugin-XMLRPC-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-XMLRPC/
COMMENT=	Dispatch XMLRPC with Catalyst

DEPENDS+=	p5-Catalyst>=5.01:../../wip/p5-Catalyst
DEPENDS+=	p5-RPC-XML>=0.45:../../net/p5-RPC-XML

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Plugin/XMLRPC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
