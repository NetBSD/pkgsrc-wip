# $NetBSD: Makefile,v 1.2 2008/05/24 15:34:13 tnn2 Exp $

DISTNAME=		MARC-Charset-0.98
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~esummers/MARC-Charset-0.98
COMMENT=		Converts MARC-8 character sets to Unicode (UTF-8)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Class-Accessor>=0.30:../../devel/p5-Class-Accessor
DEPENDS+=	p5-XML-SAX>=0.16:../../textproc/p5-XML-SAX
DEPENDS+=	p5-Unicode-Normalize>=1.02:../../wip/p5-Unicode-Normalize

PERL5_PACKLIST= auto/MARC/Charset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
