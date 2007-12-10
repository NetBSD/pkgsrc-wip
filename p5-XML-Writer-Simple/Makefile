# $NetBSD: Makefile,v 1.1.1.1 2007/12/10 09:37:22 netcap Exp $
#

DISTNAME=	XML-Writer-Simple-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/~ambs/XML-Writer-Simple-0.01/
COMMENT=	Perl module for writing XML documents
DEPENDS=	p5-XML-DT>=0.42:../../wip/p5-XML-DT	\
		p5-XML-DTDParser>=2.0:../../wip/p5-XML-DTDParser

PERL5_PACKLIST=		auto/XML/Writer/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
