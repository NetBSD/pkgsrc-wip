# $NetBSD: Makefile,v 1.3 2012/10/04 19:12:08 asau Exp $

DISTNAME=	XML-Writer-Simple-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/XML-Writer-Simple/
COMMENT=	Perl module for writing XML documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-DT>=0.42:../../wip/p5-XML-DT
DEPENDS+=	p5-XML-DTDParser>=2.01:../../wip/p5-XML-DTDParser

PERL5_PACKLIST=		auto/XML/Writer/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
