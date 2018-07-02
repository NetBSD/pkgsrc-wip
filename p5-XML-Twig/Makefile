# $NetBSD: Makefile,v 1.4 2013/05/14 02:26:40 jgoamakf Exp $
#

DISTNAME=	XML-Twig-3.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/XML::Twig
COMMENT=	Perl module for processing huge XML documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-XPathEngine-[0-9]*:../../textproc/p5-XML-XPathEngine
DEPENDS+=	p5-Encode-[0-9]*:../../textproc/p5-Encode
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

PERL5_PACKLIST=		auto/XML/Twig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
