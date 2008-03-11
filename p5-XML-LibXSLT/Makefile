# $NetBSD: Makefile,v 1.4 2008/03/11 02:07:27 hitscan Exp $
#

DISTNAME=	XML-LibXSLT-1.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITES_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-LibXSLT/
COMMENT=	Interface to the Gnome libxslt library

DEPENDS+=	p5-XML-LibXML>=1.52:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/LibXSLT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
