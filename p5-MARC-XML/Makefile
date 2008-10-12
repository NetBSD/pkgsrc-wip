# $NetBSD: Makefile,v 1.3 2008/10/12 17:37:30 absd Exp $

DISTNAME=		MARC-XML-0.87
PKGNAME=		p5-MARC-XML-0.87
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~kados/MARC-XML-0.87
COMMENT=		MARC-Record extension to work with MARC21slim XML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-MARC-Record>=2.0.0:../../databases/p5-MARC-Record
DEPENDS+=	p5-XML-SAX>=0.16:../../textproc/p5-XML-SAX
DEPENDS+=	p5-MARC-Charset>=0.98:../../wip/p5-MARC-Charset

PERL5_PACKLIST=	auto/MARC-XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
