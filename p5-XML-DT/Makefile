# $NetBSD: Makefile,v 1.1.1.1 2007/12/10 09:31:27 netcap Exp $
#

DISTNAME=	XML-DT-0.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/~ambs/XML-DT-0.47/
COMMENT=	Perl module for down translation of XML files

DEPENDS=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML	\
		p5-XML-DTDParser>=2.0:../../wip/p5-XML-DTDParser

PERL5_PACKLIST=		auto/XML/DT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
